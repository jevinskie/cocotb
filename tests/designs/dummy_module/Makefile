TOPLEVEL_LANG ?= verilog

TOPLEVEL := dummy_module

ifeq ($(OS),Msys)
WPWD=$(shell sh -c 'pwd -W')
else
WPWD=$(shell pwd)
endif

COCOTB?=$(WPWD)/../../..

ifeq ($(TOPLEVEL_LANG),verilog)
    VERILOG_SOURCES = $(COCOTB)/tests/designs/dummy_module/dummy_module.v
else ifeq ($(TOPLEVEL_LANG),vhdl)
    VHDL_SOURCES =  $(COCOTB)/tests/designs/dummy_module/dummy_module.vhdl
else
    $(error "A valid value (verilog or vhdl) was not provided for TOPLEVEL_LANG=$(TOPLEVEL_LANG)")
endif

include $(COCOTB)/makefiles/Makefile.inc
include $(COCOTB)/makefiles/Makefile.sim
