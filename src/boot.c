#include <ofw.h>

void (*ofw)();
void __eabi();

void __stack_chk_fail_local(void)
{
}
void __eabi(void)
{
}

void main(void)
{
	while(1)
	interpret("blink-screen", 0, 0, 0, 0);
	if (test("open"))
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
