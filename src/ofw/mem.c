#include <ofw.h>

extern void (*ofw)();

void* ofw_claim(void* virt, int32_t size, int32_t align)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                void* arg1;
		int32_t arg2;
                int32_t arg3;
		void* ret;
        } ofw_arg;

	SERVICE("claim", 6, 3, 1);

        ofw_arg.arg1 = virt;
	ofw_arg.arg2 = size;
	ofw_arg.arg3 = align;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

    
void ofw_release(void* virt, int32_t size)
{
        struct
        {  
                char* service;
                int32_t n_args;
                int32_t n_rets;
                void* arg1;
                int32_t arg2;
        } ofw_arg;

        SERVICE("release", 8, 2, 0);

        ofw_arg.arg1 = virt;
        ofw_arg.arg2 = size;

        ofw(&ofw_arg);
}

