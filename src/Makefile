CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
OBJDUMP=arm-none-eabi-objdump

CFLAGS02=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -O2 -Wall -Wextra
CFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -Wall -Wextra
ASMFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -Wall -Wextra

LDFLAGS=-T linker.ld -ffreestanding -O2 -nostdlib

EXEC=clean list binary download

SRCC=$(wildcard *.c)
OBJC=$(patsubst %.c, obj/%.o,$(SRCC))

SRCASM=$(wildcard *.s)
OBJASM=$(patsubst %.s, obj/%.o,$(SRCASM))

OBJDIR=obj

ASMOUT=$(SRCC:.c=.s)

OSNAME=kernel

print:
	echo $(OBJC)

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

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS02) -c -o $@ $<

$(OBJDIR)/%.o: %.s
	$(CC) $(ASMFLAGS) -c -o $@ $<

clean:
	rm -rf *.o
	rm -rf ../build/*.*