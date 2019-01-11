import cocotb
from cocotb.triggers import Timer
from cocotb.clock import Clock

import sys

# if set to true, this causes the simulation to fail with error:
#     0.10ns ERROR    cocotb.scheduler                            __init__.py:191  in _sim_event                      Failing test at simulator request before test run completion: Simulator shutdown prematurely
illustrate_issue = True

 # Not need to illustrate issue, can leave false
excercise_dummy_module = False

def extern_func():
    cocotb.log.info('extern_func')
    intern_func(1)
    if illustrate_issue:
        intern_func(2)
    return 0

@cocotb.function
def intern_func(i):
    cocotb.log.info('intern_func: {}'.format(i))
    yield Timer(1)
    return

@cocotb.test(expect_fail=illustrate_issue)
def issue_extern(dut):
    """ Illustate an issue with a cocotb.external call that fails when calling
    a @cocotb.function multiple times """
    dut._log.info('issue_extern starting')
    cocotb.fork(Clock(dut.clk, 5000).start())
    if excercise_dummy_module:
        dut.i = 0
        yield Timer(1)
        assert(dut.o == 1)
        dut.i = 1
        yield Timer(1)
        assert(dut.o == 0)
    r = yield cocotb.external(extern_func)()
    cocotb.log.info('extern_func returned: {}'.format(r))
    assert(r == 0)
    dut._log.info('issue_extern done')
