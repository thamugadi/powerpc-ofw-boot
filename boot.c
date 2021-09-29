#define DEVICE16               0x81080000
#define DEVICE16END            0x810FFFFF
#define VRAM                   0x80000000
#define VRAMEND                0x80FFFFFF
#define BIOS	               0xFFC00000
#define BIOSEND                0xFFFFFFFF
void begin(void)
{
	unsigned char* addr = VRAM;
	unsigned char* noise = BIOS+0x2E0000;
	while (addr < VRAMEND)
	{
		*addr = *noise; 
		addr++;
		noise++;
	}
	begin();
}

void clearscreen(void)
{
	unsigned char* addr = 0x80000000;
	while (addr < 0x80FFFFFF)
	{
		*addr = 0;
		addr++;
	}
}
