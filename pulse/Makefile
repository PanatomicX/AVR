AVR=attiny85
CLKRATE=9600000
#
AVRCC=avr-gcc
AVRDUDE=avrdude
AVRSIZE=avr-size
AVROBJCP=avr-objcopy
AVRCCOPTS= -g -DF_CPU=$(CLKRATE) -Wall -Os -mmcu=$(AVR)
RM=/bin/rm
PROG=usbtiny
PROGOPTS=
FUSE=-U lfuse:w:0x62:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m
WRITE=-U flash:w:pulse.hex

all : pulse.o pulse.elf pulse.hex size

pulse.o :
	$(AVRCC) -o pulse.o $(AVRCCOPTS) pulse.c

pulse.elf : pulse.o
	$(AVRCC) -o pulse.elf pulse.o

size : pulse.elf
	$(AVRSIZE) pulse.elf

pulse.hex : pulse.elf
	$(AVROBJCP) -j .text -j .data -O ihex pulse.elf pulse.hex

clean:
	$(RM) -f pulse.o pulse.elf pulse.hex

install: pulse.hex
	$(AVRDUDE) -p $(AVR) -c $(PROG) $(PROGOPTS) $(FUSE) $(WRITE)
