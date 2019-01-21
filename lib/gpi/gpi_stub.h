#pragma once

#include <string>

extern "C" void gpi_hello(void);

class Animal {
public:
	virtual ~Animal() {};
	void say_doze();
};

class GpiAnimal: public Animal {
public:
	virtual ~GpiAnimal() {};
	virtual void say_noise();
	virtual void say_hello();
	virtual const char* get_definition_name() { return m_definition_name.c_str(); };
protected:
	std::string m_definition_name;
};