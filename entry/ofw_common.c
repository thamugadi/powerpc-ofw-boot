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

        char _service[5] = "test";
        ofw_arg.service = _service;

        ofw_arg.n_args = 1;
        ofw_arg.n_rets = 1;
        ofw_arg.arg = name;

        ofw(&ofw_arg);

        return ofw_arg.ret;
}

