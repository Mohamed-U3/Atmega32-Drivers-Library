# MCU Type
MCU = atmega32

# Clock Frequency (adjust if needed)
F_CPU = 16000000UL

# Compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -Os -DF_CPU=$(F_CPU)

# AVR tools
OBJCOPY = avr-objcopy
SIZE = avr-size

# File names
TARGET = main
FREERTOS_PATH = source/
OUTPUT_PATH = output/
SRC = $(TARGET).c \
	  $(FREERTOS_PATH)tasks.c \
      $(FREERTOS_PATH)queue.c \
      $(FREERTOS_PATH)list.c \
      $(FREERTOS_PATH)port.c \
      $(FREERTOS_PATH)heap_1.c
ELF = $(TARGET).elf
HEX = $(TARGET).hex

# Default rule: Compile everything
all: $(HEX)

$(OUTPUT_PATH):
	mkdir -p $(OUTPUT_PATH)
	
# Compile C file into ELF
$(ELF): $(SRC) | $(OUTPUT_PATH)
	$(CC) $(CFLAGS) -o $(OUTPUT_PATH)$(ELF) $(SRC)

# Convert ELF to HEX
$(HEX): $(ELF) | $(OUTPUT_PATH)
	$(OBJCOPY) -O ihex -j .text -j .data $(OUTPUT_PATH)$(ELF) $(OUTPUT_PATH)$(HEX)

# Check size of the compiled program
size: $(ELF)
	$(SIZE) --format=avr --mcu=$(MCU) $(OUTPUT_PATH)$(ELF)

# Clean up generated files
clean:
	rm -f $(OUTPUT_PATH)$(ELF) $(OUTPUT_PATH)$(HEX)
	
clear: clean
