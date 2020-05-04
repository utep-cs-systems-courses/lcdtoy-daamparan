COMMON_OBJECTS	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler for internal make rules
CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: blinkBuzz.elf

#additional rules for files
blinkBuzz.elf: ${COMMON_OBJECTS} font-5x7.o font-8x12.o lcdutils.o lcddraw.o p2_interrupt_handler.o led.o switches.o buzzer.o stateMachine.o wdInterruptHandler.o state_1.o blinkBuzz.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinkBuzz.elf
	msp430loader.sh blinkBuzz.elf

clean:
	rm -f *.o *.elf
