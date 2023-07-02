#include <ofw.h>

extern void (*ofw)();

int32_t ofw_milliseconds(void)
{
        struct
        {       
                char* service;
                int32_t n_args;
                int32_t n_rets;
                int32_t ret;        
        } ofw_arg;
 
        SERVICE("milliseconds", 13, 0, 1);
        
        ofw(&ofw_arg);

	return ofw_arg.ret;
}
