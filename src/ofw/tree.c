#include <ofw.h>

extern void (*ofw)();

phandle ofw_child(phandle _child)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                phandle arg;
                phandle ret;
        } ofw_arg;

	SERVICE("child", 6, 1, 1);

        ofw_arg.arg = _child;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

phandle ofw_parent(phandle _parent)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                phandle arg;
                phandle ret;
        } ofw_arg;

	SERVICE("parent", 7, 1, 1);

        ofw_arg.arg = _parent;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

phandle ofw_instance_to_package(ihandle instance)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                ihandle arg;
                phandle ret;
        } ofw_arg;

	SERVICE("instance-to-package", 20, 1, 1);

        ofw_arg.arg = instance;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int32_t ofw_getproplen(phandle node, char* name)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                phandle arg1;
                char* arg2;
                int32_t ret;
        } ofw_arg;

	SERVICE("getproplen", 11, 2, 1);

        ofw_arg.arg1 = node;
        ofw_arg.arg2 = name;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int32_t ofw_getprop(phandle node, char* name, void* buf, int32_t buflen)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                phandle arg1;
                char* arg2;
                void* arg3;
                int32_t arg4;
                int32_t ret;
        } ofw_arg;

	SERVICE("getprop", 8, 4, 1);

        ofw_arg.arg1 = node;
        ofw_arg.arg2 = name;
        ofw_arg.arg3 = buf;
        ofw_arg.arg4 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int32_t ofw_nextprop(phandle node, char* previous, void* buf)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                phandle arg1;
                char* arg2;
                void* arg3;
                int32_t ret;
        } ofw_arg;

	SERVICE("nextprop", 9, 3, 1);

        ofw_arg.arg1 = node;
        ofw_arg.arg2 = previous;
        ofw_arg.arg3 = buf;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int32_t ofw_setprop(phandle node, char* name, void* buf, int32_t len)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                phandle arg1;
                char* arg2;
                void* arg3;
                int32_t arg4;
                int32_t ret;
        } ofw_arg;

	SERVICE("setprop", 8, 4, 1);

        ofw_arg.arg1 = node;
        ofw_arg.arg2 = name;
        ofw_arg.arg3 = buf;
        ofw_arg.arg4 = len;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}
  
int32_t ofw_canon(char* device, void* buf, int32_t buflen)   
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                char* arg1;
                void* arg2;
                int32_t arg3;
                int32_t ret;
        } ofw_arg;

	SERVICE("canon", 6, 3, 1);

        ofw_arg.arg1 = device;
        ofw_arg.arg2 = buf;
        ofw_arg.arg3 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

phandle ofw_finddevice(char* device)              
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                char* arg1;  
                int32_t ret;
        } ofw_arg;

	SERVICE("finddevice", 11, 1, 1);

        ofw_arg.arg1 = device;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int32_t ofw_instance_to_path(ihandle instance, void* buf, int32_t buflen)
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

	SERVICE("instance-to-path", 17, 3, 1);

        ofw_arg.arg1 = instance;
        ofw_arg.arg2 = buf;
        ofw_arg.arg3 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;

}

int32_t ofw_package_to_path(phandle package, void* buf, int32_t buflen)
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

	SERVICE("package-to-path", 16, 3, 1);

        ofw_arg.arg1 = package;
        ofw_arg.arg2 = buf;
        ofw_arg.arg3 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;

}

void* ofw_call_method(char* method, ihandle instance, int32_t* stack_args, int32_t n_stack_args, int32_t n_ret_args, int32_t* retaddr)
{
	struct
	{
		char* service;
		int32_t n_args;
		int32_t n_rets;
		char* arg1;
		ihandle arg2;
		int32_t argN[n_stack_args];
		int32_t ret1;
		int32_t retN[n_ret_args];
	} ofw_arg;

	SERVICE("call-method", 12, 2+n_stack_args, n_ret_args);

	ofw_arg.arg1 = method;
	ofw_arg.arg2 = instance;

	int i;
	for (i = 0; i < n_stack_args; i++)
	{
		ofw_arg.argN[i] = stack_args[i];
	}

	ofw(&ofw_arg);

	*retaddr = ofw_arg.ret1;
	for (i = 1; i < n_ret_args+1; i++)
	{
		retaddr[i] = ofw_arg.retN[i];
	}

	return retaddr;
}

