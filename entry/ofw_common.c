#include <ofw.h>

extern void (*ofw)();

int ofw_test(char* name)
{
        struct 
        {
                char* service;
                int n_args;
                int n_rets;
                char* arg;
                int ret;
        } ofw_arg;

	SERVICE("test", 5, 1, 1);

        ofw_arg.arg = name;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

