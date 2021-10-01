#define beige         0xBE
#define mac99         0x5A
#define __VRAM__BEIGE 0x80000000
#define __VRAM__MAC99 0x81000000
#define __BIOS__BEIGE 0xFFC00000
#define __BIOS__MAC99 0xFFF00000



unsigned char IO_TYPE;
unsigned char* p_vram;
unsigned char* p_bios;



void get_io_type(void)
{
        if (*(unsigned char*)__VRAM__BEIGE == beige) IO_TYPE = beige;
	else if (*(unsigned char*)__VRAM__MAC99 == mac99) IO_TYPE = mac99;

}
void init(void)
{
	if (IO_TYPE == beige)
	{
                p_vram = __VRAM__BEIGE;
		p_bios = __BIOS__BEIGE;

	}
	else if (IO_TYPE == mac99)
	{
		p_vram = __VRAM__MAC99;
		p_bios = __BIOS__MAC99;
	}
}

void main(void)
{
	get_io_type();
	init();
	for(;;);
}

void clearscreen(unsigned char a, unsigned char b)
{
	init();
	for (unsigned int i = 0; i<0x100000; i++)
	{
		*p_vram = a; 
		p_vram++;
		*p_vram = b; 
		p_vram++;
	}
}

void noisescreen(void)
{
	init();
	for (unsigned int i = 0; i<0x200000; i++)
	{
		*p_vram = *(p_bios+0x2F0000+i);
		p_vram++;

	}
}
