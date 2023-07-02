#include <ofw.h>

extern void (*ofw)();

ihandle ofw_open(char* device_specifier)
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

void ofw_close(ihandle instance)
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

int32_t ofw_read(ihandle instance, void* addr, int32_t len)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                ihandle arg1;
		void* arg2;
		int32_t arg3;
		int32_t ret;
        } ofw_arg;

	SERVICE("read", 5, 3, 1);

	ofw_arg.arg1 = instance;
	ofw_arg.arg2 = addr;
	ofw_arg.arg3 = len;

	ofw(&ofw_arg);

	return ofw_arg.ret;
}

int32_t ofw_write(ihandle instance, void* addr, int32_t len)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                ihandle arg1;
                void* arg2;
                int32_t arg3; 
                int32_t ret;
        } ofw_arg;
         
        SERVICE("write", 6, 3, 1);
        
        ofw_arg.arg1 = instance;
        ofw_arg.arg2 = addr;
        ofw_arg.arg3 = len;
        
        ofw(&ofw_arg);
        
        return ofw_arg.ret;

}

int32_t ofw_seek(ihandle instance, int32_t pos_hi, int32_t pos_lo)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                ihandle arg1;
                int32_t* arg2;
                int32_t arg3; 
                int32_t ret;
        } ofw_arg;
         
        SERVICE("seek", 5, 3, 1);
        
        ofw_arg.arg1 = instance;
        ofw_arg.arg2 = pos_hi;
        ofw_arg.arg3 = pos_lo;
        
        ofw(&ofw_arg);
        
        return ofw_arg.ret;

}
