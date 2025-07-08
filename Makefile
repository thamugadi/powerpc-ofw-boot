MACHINE = mac99
PPC = powerpc-eabi
QEMU = qemu-system-ppc
RES = 1600x900x32
CPU = g4
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

bootinfo.txt: loader/def.fth loader/load.fth
	@echo "<CHRP-BOOT><BOOT-SCRIPT>" > $@ 
	@sed 's/>/\&gt;/g; s/</\&lt;/g' $^ >> $@
	@echo "</BOOT-SCRIPT></CHRP-BOOT>" >> $@ 
	@printf "\0" >> $@

kernel.elf: linker.ld $(OBJECTS)
	$(PPC)-ld -T $^ -o $@

%.elf: %.c
	$(PPC)-gcc -I include -c $< -o $@

%.elf: %.s
	$(PPC)-as -c $< -o $@

clean:
	rm -f *.APM *.txt *.elf
	find src -name "*.elf" -type f -delete

run:
	$(QEMU) -hda *.APM -g $(RES) -machine $(MACHINE) -cpu $(CPU)

debug:
	$(QEMU) -hda *.APM -d in_asm -g $(RES) -machine $(MACHINE) -cpu $(CPU)
gdb:
	$(QEMU) -hda *.APM -s -S -g $(RES) -machine $(MACHINE) -cpu $(CPU)
