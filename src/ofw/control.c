#include <ofw.h>

extern void (*ofw)();

void boot(char* bootspec)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                char* arg;
        } ofw_arg;

	SERVICE("boot", 5, 1, 0);
	
        ofw_arg.arg = bootspec;

        ofw(&ofw_arg);
}

void enter(void)
{
	struct
	{
		char* service;
		int32_t n_args;
		int32_t n_rets;
	} ofw_arg;

	SERVICE("enter", 6, 0, 0);

	ofw(&ofw_arg);
}

void ofw_exit(void)
{       
        struct
        {       
                char* service;
                int32_t n_args;
                int32_t n_rets;
        } ofw_arg;
        
        SERVICE("exit", 5, 0, 0);
        
        ofw(&ofw_arg);
}

void chain(void* virt, int32_t size, void* entry, void* args, int32_t len)
{
	struct
	{
		char* service;
		int32_t n_args;
		int32_t n_rets;
		void* arg1;
		int32_t arg2;
		void* arg3;
		void* arg4;
		int32_t arg5;
	} ofw_arg;
	
	SERVICE("chain", 6, 5, 0);

	ofw_arg.arg1 = virt;
	ofw_arg.arg2 = size;
	ofw_arg.arg3 = entry;
	ofw_arg.arg4 = args;
	ofw_arg.arg5 = len;

	ofw(&ofw_arg);
}
