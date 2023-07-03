#include <ofw.h>

void puts(char* str, int len)
{
	char cmd[len+8]; 
	cmd[0] = '.'; cmd[1] = '"';
	cmd[2] = ' ';
	for (int i = 3; i < len+3; i++)
	{
		cmd[i] = str[i-3];
	}
	cmd[len+3] = '"'; cmd[len+4] = ' ';
	cmd[len+5] = 'c'; cmd[len+6] = 'r';
	cmd[len+7] = 0;
	ofw_interpret(cmd, 0, 0, 0, 0);
}
