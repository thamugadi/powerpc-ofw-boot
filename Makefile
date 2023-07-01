MACHINE = mac99
PPC = powerpc-eabi
QEMU = qemu-system-ppc
RES = 1600x900x32

SOURCES_C = $(shell find src -name "*.c")
SOURCES_S = $(shell find src -name "*.s")
OBJECTS = $(SOURCES_C:.c=.elf) $(SOURCES_S:.s=.elf)

.PHONY: clean run debug beige

DISK.APM: kernel.elf bootinfo.txt kpartx/kpartx.sh
	dd bs=512K count=2 if=/dev/zero of=DISK.APM
	parted DISK.APM --script mklabel mac mkpart primary hfs+ 32.8KB 100%
	sudo chmod +x kpartx/kpartx.sh
	sudo ./kpartx/kpartx.sh
	sudo mkdir -p /mnt/ppc /mnt/boot
	sudo cp bootinfo.txt /mnt/ppc
	sudo cp kernel.elf /mnt/boot
	sudo umount /mnt/
	sudo kpartx -d DISK.APM

bootinfo.txt: loader/load.fth loader/def.fth
	echo "<chrp-boot><boot-script>" >> bootinfo.txt
	cat loader/def.fth >> bootinfo.txt
	cat loader/load.fth >> bootinfo.txt
	echo "</boot-script></chrp-boot>" >> bootinfo.txt

kernel.elf: $(OBJECTS)
	$(PPC)-ld -Ttext=0x02000000 -Tdata=0x02100000 $^ -o $@

%.elf: %.c
	$(PPC)-gcc -I include -c $< -o $@

%.elf: %.s
	$(PPC)-as -c $< -o $@

clean:
	rm -f *.APM *txt
	find src -name "*.elf" -type f -delete

run:
	$(QEMU) -hda *.APM -g $(RES) -machine $(MACHINE)

debug:
	$(QEMU) -hda *.APM -d in_asm -g $(RES) -machine $(MACHINE)
