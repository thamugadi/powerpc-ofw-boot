: initmsg ." powerpc-ofw-boot" cr ;
: fba frame-buffer-adr ;
: beige-fba 80000000 ; : mac99-fba 81000000 ;
: hardware-error ." Hardware not supported." cr ;
: beige-message  ." Beige hardware detected" cr ;
: mac99-message  ." mac99 hardware detected" cr ;
: beige-magic-number 0BE ;
: mac99-magic-number 05A ;
: magic-number-offset 0 ;
: width-offset 4 ;
: height-offset 8 ;
