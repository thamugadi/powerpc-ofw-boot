#include <ofw.h>

extern void (*ofw)();

int32_t test(char* name)
{
        struct 
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                char* arg;
                int32_t ret;
        } ofw_arg;

	SERVICE("test", 5, 1, 1);

        ofw_arg.arg = name;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

