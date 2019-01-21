#include <stdio.h>
#include <dlfcn.h>
#include <assert.h>

#include "mti.h"
#include "acc_vhdl.h"   // Messy :(
#include "acc_user.h"

#include <Python.h>

#include "fli_stub.h"

void *py_handle;
typedef void (*pyinit_t)(void);
typedef int (*pyfin_t)(void);
pyinit_t pyinit;
pyfin_t pyfin;
void *self_handle;
void *pyinitp = (void*)Py_Initialize;

extern "C"
void handle_restart(void *data) {
    fprintf(stderr, "%s\n", __func__);
}

typedef void (*restartcb_t)(void*);

void mti_AddRestartCB(restartcb_t cb, void *data);

void cocotb_init(void)
{
    fprintf(stderr, "cocotb_init called\n");
    mti_AddRestartCB(handle_restart, NULL);
    fprintf(stderr, "cocotb_init done\n");
}

extern "C" void gpi_hello(void);

__attribute__((constructor))
void fli_ctor(void) {
	int ret;
    fprintf(stderr, "fli stub ctor %p\n", cocotb_init);
    // py_handle = dlopen("/home/jevin/base/python/3.7.2-32/lib/libpython3.7m.so",  RTLD_LAZY | RTLD_GLOBAL);
    // fprintf(stderr, "py_handle = %p\n", py_handle);
    // assert(py_handle);
    // pyinit = dlsym(py_handle, "Py_Initialize");
    // assert(pyinit);
    // pyfin = dlsym(py_handle, "Py_FinalizeEx");
    // assert(pyfin);
    // pyinit();
    fprintf(stderr, "pyinitp: %p\n", pyinitp);
    Py_Initialize();
#if 1
    ret = PyRun_SimpleString("from time import time,ctime\n"
                        "import sys\n"
                        "import math\n"
                        "import ctypes\n"
                        "import xml.parsers.expat\n"
                        "import xml.etree.ElementTree\n"
                        "import heapq\n"
                        "import hashlib\n"
                        "import os\n"
                        "import random\n"
                        "import mmap\n"
                        "import _opcode\n"
                        "print(os.getpid())\n"
                       "print('Today is', ctime(time()), file=sys.stderr, flush=True)\n");
#else
    ret = PyRun_SimpleString(
                    "import sys\n"
                    "print('hello from python', file=sys.stderr, flush=True)\n");
#endif
    fprintf(stderr, "simplestring() = %d\n", ret);
    // self_handle = dlopen("/home/jevin/code/hdl/cocotb/git/cocotb/build/libs/i686/libfli.so", RTLD_LAZY | RTLD_GLOBAL);
    fprintf(stderr, "self_handle: %p\n", self_handle);
    gpi_hello();
    GpiAnimal gpi_animal;
    gpi_animal.say_noise();
    gpi_animal.say_hello();
    gpi_animal.say_doze();
    fprintf(stderr, "gpi_animal thing: %s\n", gpi_animal.get_definition_name());
    FliAnimal fli_animal;
    fli_animal.say_noise();
    fli_animal.say_hello();
    fli_animal.say_doze();
    fprintf(stderr, "fli_animal thing: %s\n", fli_animal.get_definition_name());
    fprintf(stderr, "fli stub ctor done\n");
}

__attribute__((destructor))
void fli_dtor(void) {
	int ret;
    fprintf(stderr, "fli stub dtor\n");
    // ret = pyfin();
    // ret = Py_FinalizeEx();
    ret = 242;
    fprintf(stderr, "Py_FinalizeEx() = %d\n", ret);
    // ret = dlclose(py_handle);
    ret = 243;
    fprintf(stderr, "dlclose(py_handle) = %d\n", ret);
    fprintf(stderr, "fli stub dtor done\n");
}

void FliAnimal::say_noise() {
    fprintf(stderr, "say_noise fli woof\n");
}
