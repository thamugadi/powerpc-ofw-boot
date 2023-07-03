#include <ofw.h>

void (*ofw)();
void __eabi();

void __stack_chk_fail_local(void)
{
}
void __eabi(void)
{
}

//void* ofw_interpret(char* cmd, int32_t* stack_args, int n_stack_args, int n_ret_args, int32_t* reta
void main(void)
{
	puts("Press any key to continue", 25);
	ofw_interpret("blink-screen", 0, 0, 0, 0);
	ofw_interpret("key", 0, 0, 1, (int32_t*)0x03020000);

	puts("Starting...", 11);
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
