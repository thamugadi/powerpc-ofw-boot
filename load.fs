." Booting through OpenFirmware..." cr
frame-buffer-adr

.
: rep dup 0 do i . loop ;
500 rep

boot hd:,\boot\kernel.elf
