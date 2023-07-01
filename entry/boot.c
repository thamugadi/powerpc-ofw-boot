#include "boot.h"
void __stack_chk_fail_local(void)
{
}
void __eabi(void)
{
}

void main(void)
{
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
