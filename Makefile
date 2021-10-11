MACHINE=mac99
PPC=powerpc-linux-gnu
QEMU=qemu-system-ppc
RES=1280x768x32

DISK.APM: kernel.elf bootinfo.txt scripts/kpartx.sh
	dd bs=512K count=2 if=/dev/zero of=DISK.APM
	parted DISK.APM --script mklabel mac mkpart primary hfs+ 32.8KB 100%
	sudo chmod +x scripts/kpartx.sh
	sudo ./scripts/kpartx.sh
	sudo mkdir /mnt/ppc
	sudo mkdir /mnt/boot
	sudo cp bootinfo.txt /mnt/ppc
	sudo cp kernel.elf /mnt/boot
	sudo umount /mnt/
	sudo kpartx -d DISK.APM
bootinfo.txt: loader/load.fth
	echo "<chrp-boot><boot-script>" >> bootinfo.txt
	cat loader/load.fth >> bootinfo.txt
	echo "</boot-script></chrp-boot>" >> bootinfo.txt
kernel.elf: start.elf boot.elf 
	$(PPC)-ld -Ttext=0x200000 start.elf boot.elf -o kernel.elf
boot.elf: entry/boot.c 
	$(PPC)-gcc -c entry/boot.c -o boot.elf
start.elf: entry/start.s
	$(PPC)-as -c entry/start.s -o start.elf
clean:
	rm *.APM *elf *txt 
run:
	$(QEMU) -hda *.APM -g $(RES) -machine $(MACHINE) 
debug:
	$(QEMU) -hda *.APM -d in_asm -g $(RES) -machine $(MACHINE)
all:
	make clean && make && make run
