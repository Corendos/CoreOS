CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -std=gnu99 -O2 -Wall -Wextra
ASMFLAGS=-mcpu=arm1176jzf-s -fpic -ffreestanding -Wall -Wextra

LDFLAGS=-T linker.ld -ffreestanding -O2 -nostdlib

EXEC=compile

SRCC=$(wildcard *.c)
OBJC=$(SRCC:.c=.o)

SRCASM=$(wildcard *.s)
OBJASM=$(SRCASM:.s=.o)

OSNAME=myos

all: $(EXEC)

compile:  $(OBJC) $(OBJASM)
	$(CC) -o ../build/$(OSNAME).elf $(LDFLAGS) $(OBJASM) $(OBJC)
	

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: %.s
	$(CC) $(ASMFLAGS) -o $@ -c $^

clean:
	rm -rf *.o

binary: all
	$(OBJCOPY) ../build/$(OSNAME).elf -O binary ../build/$(OSNAME).bin