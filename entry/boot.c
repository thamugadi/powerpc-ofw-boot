#include "boot.h"
void __stack_chk_fail_local(void)
{
}
void __eabi(void)
{
}

int ofw_test(const char* name)
{
	struct 
	{
		char* service;
		int n_args;
		int n_rets;
		char* arg;
		int ret;
	} ofw_arg;

	char _service[5] = "test";
	ofw_arg.service = _service;

	ofw_arg.n_args = 1;
	ofw_arg.n_rets = 1;
	ofw_arg.arg = name;

	ofw(&ofw_arg);

	return ofw_arg.ret;
}

void main(void)
{
	asm volatile("stw 5, %0" : "=m"(ofw));
	if (ofw_test("open"))
	{
		asm("mr 27, 28");
		asm("b $");
	}
	else
	{
		asm("mr 30, 31");
		asm("b $");
	}
}
