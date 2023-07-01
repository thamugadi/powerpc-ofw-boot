.globl _start
.extern ofw
_start:
lis 9, ofw@ha
ori 9, 9, ofw@l
stw 5, 0(9)
b main
