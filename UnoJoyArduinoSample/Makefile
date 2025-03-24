#
# A simple makefile for managing build of project composed of C source files.
#
OS_TAG := $(shell uname -s)

# It is likely that default C compiler is already gcc, but explicitly
# set, just to be sure
CC = avrdude

# The CFLAGS variable sets compile flags for gcc:
#  -g        compile with debug information
#  -Wall     give verbose compiler warnings
#  -O0       do not optimize generated code
#  -std=c99  use the C99 standard language definition
CFLAGS = -C/Users/jeff/Applications/Developer/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -I/Users/jeff/Projects/arduino/libraries/UnoJoy

# The LDFLAGS variable sets flags for linker
#  -lm   says to link in libm (the math library)
LDFLAGS = -P/dev/cu.wchusbserial1d133120 -b57600 -D -Uflash:w:/Users/jeff/Projects/arduino/UnoJoyArduinoSample/main.cpp

# In this section, you list the files that are part of the project.
# If you add/change names of source files, here is where you
# edit the Makefile.
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main

# The first target defined in the makefile is the one
# used when make is invoked with no argument. Given the definitions
# above, this Makefile file will build the one named TARGET and
# assume that it depends on all the named OBJECTS files.

$(TARGET) : $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

all: $(OS_TAG)
		@echo "INFO: Compiling and linking main stub for ${OS_TAG}..."

Darwin:
		avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR -I/Users/jeff/Applications/Developer/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino -I/Users/jeff/Applications/Developer/Arduino.app/Contents/Java/hardware/arduino/avr/variants/eightanaloginputs -I/Users/jeff/Projects/arduino/libraries/UnoJoy main.cpp -o main
		#avrdude -C/Users/jeff/Applications/Developer/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/cu.wchusbserial1d133120 -b57600 -D -Uflash:w:/Users/jeff/Projects/arduino/UnoJoyArduinoSample/main.cpp

# Phony means not a "real" target, it doesn't build anything
# The phony target "clean" is used to remove all compiled object files.

.PHONY: clean

clean:
		@rm -f $(TARGET) $(OBJECTS) core
