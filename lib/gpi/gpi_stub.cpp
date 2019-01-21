#include <stdio.h>

#include "gpi_stub.h"


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

void gpi_hello(void) {
	fprintf(stderr, "gpi_hello\n");
}

void Animal::say_doze() {
	fprintf(stderr, "say_doze base zzzzz\n");
}

void GpiAnimal::say_noise() {
	fprintf(stderr, "say_noise gpi moo\n");
}

void GpiAnimal::say_hello() {
	fprintf(stderr, "say_hello gpi\n");
}