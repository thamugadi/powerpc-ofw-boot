." powerpc-ofw-boot : Booting through OpenFirmware..." cr
\ storing 0xBE for beige, 0x5A for mac99
\ cannot use superior / inferior symbols (bootinfo.txt)
: superior - dup abs = ;
: inferior dup superior 1 + ; 
frame-buffer-adr 80000000 = if
." Beige" cr
10000 0 do BE i 80000000 + c! BE 1 i + 80000000 + c! 2 +loop
then
frame-buffer-adr 81000000 = if
." mac99" cr
10000 0 do 5A i 81000000 + c! 5A 1 i + 81000000 + c! 2 +loop 
then
boot hd:,\boot\kernel.elf
