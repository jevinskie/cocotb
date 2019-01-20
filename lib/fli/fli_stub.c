#include <stdio.h>
#include <dlfcn.h>
#include <assert.h>

#include "mti.h"
#include "acc_vhdl.h"   // Messy :(
#include "acc_user.h"

#include <Python.h>

void *py_handle;
typedef void (*pyinit_t)(void);
typedef int (*pyfin_t)(void);
pyinit_t pyinit;
pyfin_t pyfin;

void cocotb_init(void)
{
    fprintf(stderr, "cocotb_init called\n");
}

__attribute__((constructor))
void ctor(void) {
	int ret;
    fprintf(stderr, "fli stub ctor %p\n", cocotb_init);
    py_handle = dlopen("/home/jevin/base/python/3.7.2-32/lib/libpython3.7m.so",  RTLD_LAZY | RTLD_GLOBAL);
    assert(py_handle);
    // pyinit = dlsym(py_handle, "Py_Initialize");
    // assert(pyinit);
    // pyfin = dlsym(py_handle, "Py_FinalizeEx");
    // assert(pyfin);
    // pyinit();
    Py_Initialize();
    ret = PyRun_SimpleString("from time import time,ctime\n"
    					"import sys\n"
                       "print('Today is', ctime(time()), file=sys.stderr, flush=True)\n");
    fprintf(stderr, "simplestring() = %d\n", ret);
    fprintf(stderr, "fli stub ctor done\n");
}

__attribute__((destructor))
void dtor(void) {
	int ret;
    fprintf(stderr, "fli stub dtor\n");
    // ret = pyfin();
    ret = Py_FinalizeEx();
    fprintf(stderr, "Py_FinalizeEx() = %d\n", ret);
    ret = dlclose(py_handle);
    fprintf(stderr, "dlclose(py_handle) = %d\n", ret);
    fprintf(stderr, "fli stub dtor done\n");
}
