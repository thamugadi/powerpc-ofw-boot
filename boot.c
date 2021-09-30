void begin(void)
{
	unsigned char type;
	unsigned char *ptr_beige = 0x80000000;
	unsigned char *ptr_mac99 = 0x81000000;
	if (*ptr_beige == 0xBE) type = 0xBE;
	if (*ptr_mac99 == 0x5A) type = 0x5A;
	for(;;);
}
