CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
OBJDUMP=arm-none-eabi-objdump

CFLAGS02=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -O2 -Wall -Wextra
CFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -Wall -Wextra
ASMFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -Wall -Wextra

LDFLAGS=-T linker.ld -ffreestanding -O2 -nostdlib

EXEC=clean list binary download

SRCC=$(wildcard *.c)
OBJC=$(SRCC:.c=.o)

SRCASM=$(wildcard *.s)
OBJASM=$(SRCASM:.s=.o)

ASMOUT=$(SRCC:.c=.s)

OSNAME=kernel

all: $(EXEC)

compile:  $(OBJC) $(OBJASM)
	$(CC) -o ../build/$(OSNAME).elf $(LDFLAGS) $(OBJASM) $(OBJC)

asm: $(ASMOUT)

binary: compile
	$(OBJCOPY) ../build/$(OSNAME).elf -O binary ../build/$(OSNAME).img

download: binary
	sudo mount /dev/mmcblk0p1 /media/corendos/boot/
	sudo cp ../build/$(OSNAME).img /media/corendos/boot/
	sudo umount /dev/mmcblk0p1

list: compile
	$(OBJDUMP) -D ../build/$(OSNAME).elf > ../build/$(OSNAME).list

%.s: %.c
	$(CC) $(CFLAGS02) -S -o asm/$@ -c $^

%.o: %.c
	$(CC) $(CFLAGS02) -o $@ -c $^

%.o: %.s
	$(CC) $(ASMFLAGS) -o $@ -c $^

clean:
	rm -rf *.o
	rm -rf ../build/*.*