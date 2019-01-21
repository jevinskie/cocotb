#include <stdio.h>


__attribute__((constructor))
void gpi_ctor(void) {
    fprintf(stderr, "gpi stub ctor\n");
    fprintf(stderr, "gpi stub ctor done\n");
}

__attribute__((destructor))
void gpi_dtor(void) {
    fprintf(stderr, "gpi stub dtor\n");
    fprintf(stderr, "gpi stub dtor done\n");
}

extern "C"
void gpi_hello(void) {
	fprintf(stderr, "gpi_hello\n");
}
