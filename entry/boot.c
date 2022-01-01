#include "boot.h"
void __stack_chk_fail_local(void){}
void get_io_type(void)
{
        if (*(unsigned char*)__VRAM__BEIGE == beige) IO_TYPE = beige;
	else if (*(unsigned char*)__VRAM__MAC99 == mac99) IO_TYPE = mac99;
	if (IO_TYPE == beige)
	{
		screen_width = (*(unsigned int*)(__VRAM__BEIGE+4));
                screen_height = (*(unsigned int*)(__VRAM__BEIGE+8)); 

	}
	else if (IO_TYPE == mac99)
	{
		screen_width = (*(unsigned int*)(__VRAM__MAC99+4));
                screen_height = (*(unsigned int*)(__VRAM__MAC99+8));
	}
}
void init(void)
{
	if (IO_TYPE == beige)
	{
		p_vram = __VRAM__BEIGE;
		p_bios = __BIOS__BEIGE;
		p_timer= __TIMR__BEIGE;
	}
	else if (IO_TYPE == mac99)
	{
		p_vram = __VRAM__MAC99;
		p_bios = __BIOS__MAC99;
		p_timer= __TIMR__MAC99;
	}
}

void main(void)
{
	get_io_type();
	init();
	int N = screen_width;
	int i,j,ip1,jp1,nei;
	unsigned int random;
	unsigned char universe[N][N];
	unsigned char universe2[N][N];
	unsigned char* junk_beige = 0x81040000;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++)
        {
		if (IO_TYPE == mac99)
		{
			random = (*p_timer + *p_bios);
                	if (!(random%7)) universe[i][j] = 1;
        		else universe[i][j] = 0;
			p_bios++;
		}
		else if (IO_TYPE == beige)
		{
			random = (*junk_beige);
                        if (!(random%3)) universe[i][j] = 1;
                        else universe[i][j] = 0;
			junk_beige++;
		}
        }
	for(;;)	
	{
		init();
		memcpy(p_vram, p_vram+255, 400000);

		p_vram += 400000;
		for (i = 0; i < N; i++) for (j = 0; j < N; j++)
		{
			if (universe[i][j]) fillscreen(p_vram, 255,255,255,1);
			else fillscreen(p_vram,200 ,210,5,1);
			p_vram+=4;
		}
		for (i = 0; i < N; i++) for (j = 0; j < N; j++) universe2[i][j] = universe[i][j];
		for (i = 0; i < N; i++) for (j = 0; j < N; j++)
		{
			nei = 0;
			ip1 = i + 1;
			jp1 = j + 1;
			if (i == N) ip1=0;
			if (j == N) jp1=0;
			if (!i) ip1=N;
			if (!j) jp1=N;
			if (universe[i][jp1]) nei++;
			if (universe[ip1][j]) nei++;
			if (universe[i][j-1]) nei++;
			if (universe[i-1][j]) nei++;
			if (universe[ip1][jp1]) nei++;
			if (universe[ip1][j-1]) nei++;
			if (universe[i-1][jp1]) nei++;
			if (universe[i-1][j-1]) nei++;

			if (universe[i][j])
         	       	{
                	        if (nei == 2 || nei == 3) universe2[i][j] = universe[i][j];
                        	else universe2[i][j] = 0;
                	}
                	else
                	{
                        	if (nei == 3) universe2[i][j] = 1;
                        	else universe2[i][j] = universe[i][j];
                	}

		}
                for (i = 0; i < N; i++) for (j = 0; j < N; j++) universe[i][j] = universe2[i][j];
	}
}

void fillscreen(unsigned int* addr, unsigned char a, unsigned char b, unsigned char c, int n)
{
	unsigned char* ptr = addr;
	for (unsigned int i = 0; i<n; i++)
	{
		//24-bit VGA
		*ptr = a;
		ptr++;
		*ptr = b;
		ptr++;
		*ptr = c;
		ptr++;
		*ptr = 0;
		ptr++;
	}
}

void memcpy(unsigned char* dest, unsigned char* src, int n)
{
	unsigned char* destination = dest;
	unsigned char* source = src;
	for (int i = 0; i<n; i++)
	{
		*destination = *source;
		destination++; source++;
	}
}

