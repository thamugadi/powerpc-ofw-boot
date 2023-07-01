#include <ofw.h>

extern void (*ofw)();

ihandle open(char* device_specifier)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                char* arg;
                ihandle ret;
        } ofw_arg;

	SERVICE("open", 5, 1, 1);

        ofw_arg.arg = device_specifier;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

void close(ihandle instance)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                ihandle arg;
        } ofw_arg;

	SERVICE("close", 6, 1, 0);

	ofw_arg.arg = instance;

        ofw(&ofw_arg);
}

