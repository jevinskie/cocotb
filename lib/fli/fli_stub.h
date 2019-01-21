#pragma once

#include "../gpi/gpi_stub.h"

extern "C" void cocotb_init(void);

class FliAnimal: public virtual GpiAnimal {
public:
	virtual ~FliAnimal() {};
	virtual void say_noise();
};