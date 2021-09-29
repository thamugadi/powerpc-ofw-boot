void begin(void)
{
	unsigned char* addr = 0x7FFFFFFF;
	unsigned char* noise = 0xFFEE0000;
	while (addr < 0x80500000){
		*addr = *noise;
		addr++;
		noise++;
	}
	for(;;);
}
