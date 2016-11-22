ifeq ($(OS),Windows_NT)
    OS_detected := Windows

    CC="C:\\Program Files (x86)\\GNU Tools ARM Embedded\\5.4 2016q3\\bin\\arm-none-eabi-gcc"
	OBJCOPY="C:\\Program Files (x86)\\GNU Tools ARM Embedded\\5.4 2016q3\\bin\\arm-none-eabi-objcopy"
	OBJDUMP="C:\\Program Files (x86)\\GNU Tools ARM Embedded\\5.4 2016q3\\bin\\arm-none-eabi-objdump"

	LDFLAGS=-T linker\\linker.ld -ffreestanding -O2 -nostdlib

	EXEC=clean list binary

	OSNAME=..\\build\\kernel

	BUILDDIR=..\\build

	SRCASM=$(wildcard asm/*.s)
	OBJASM=$(patsubst asm/%.s, obj\\%.o,$(SRCASM))
	SRCC=$(wildcard *.c)
	OBJC=$(patsubst %.c, obj\\%.o,$(SRCC))
else
    OS_detected := $(shell uname -s)

    CC=arm-none-eabi-gcc
	OBJCOPY=arm-none-eabi-objcopy
	OBJDUMP=arm-none-eabi-objdump

	LDFLAGS=-T linker/linker.ld -ffreestanding -O2 -nostdlib

	EXEC=clean list binary download

	OSNAME=../build/kernel

	BUILDDIR=../build

	SRCASM=$(wildcard asm/*.s)
	OBJASM=$(patsubst asm/%.s, obj/%.o,$(SRCASM))
	SRCC=$(wildcard *.c)
	OBJC=$(patsubst %.c, obj/%.o,$(SRCC))
endif

CFLAGSO2=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -O2 -Wall -Wextra
CFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -Wall -Wextra
ASMFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -Wall -Wextra

ASMDIR=asm
OBJDIR=obj

all: $(EXEC)

info:
	echo $(OBJASM)

compile:  $(OBJC) $(OBJASM)
	$(CC) -o $(OSNAME).elf $(LDFLAGS) $(OBJASM) $(OBJC)

binary: compile
	$(OBJCOPY) $(OSNAME).elf -O binary $(OSNAME).img

download: binary
	sudo mount /dev/mmcblk0p1 /media/corendos/boot/
	sudo cp ../build/$(OSNAME).img /media/corendos/boot/
	sudo umount /dev/mmcblk0p1

list: compile
	$(OBJDUMP) -D $(OSNAME).elf > $(OSNAME).list

ifeq ($(OS_detected), Windows)
$(OBJDIR)\\%.o: %.c
	$(CC) $(CFLAGSO2) -c -o $@ $<

$(OBJDIR)\\%.o: $(ASMDIR)\\%.s
	$(CC) $(ASMFLAGS) -c -o $@ $<
else
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGSO2) -c -o $@ $<

$(OBJDIR)/%.o: $(ASMDIR)/%.s
	$(CC) $(ASMFLAGS) -c -o $@ $<
endif

ifeq ($(OS_detected), Windows)
clean:
	del /Q $(OBJDIR)\\*.o
	del /Q $(BUILDDIR)\\*.*
else
clean:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(OBJDIR)/*.*
endif