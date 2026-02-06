# TI-86 Program Makefile

# Compiler and flags
CC = zcc
TARGET = +ti86

CFLAGS = -clib=default -create-app -pragma-need=ansiterminal -pragma-define:ansicolumns=21 -Isrc

# Output and source files
OUTPUT = mathfunc
SOURCES = src/lcd_getkey.asm $(wildcard src/*.c src/*/*.c)

# Build directories
OBJ_DIR = obj
BIN_DIR = bin

# Default target
all: $(BIN_DIR)/$(OUTPUT).86p

# Build rule
$(BIN_DIR)/$(OUTPUT).86p: $(SOURCES) | $(BIN_DIR) $(OBJ_DIR)
	$(CC) $(TARGET) $(CFLAGS) -startup=10 -O1 -o $(OBJ_DIR)/$(OUTPUT) $(SOURCES)
	mv $(OBJ_DIR)/$(OUTPUT).86p $(BIN_DIR)/$(OUTPUT).86p
	python3 -c "f=open('$(BIN_DIR)/$(OUTPUT).86p','r+b');c='$(DESCRIPTION)'.encode('ascii')[:42].ljust(42,b'\x00');f.seek(11);f.write(c);f.close()"
	python3 -c "f=open('$(BIN_DIR)/$(OUTPUT).86p','r+b');n=b'MATHFUNC';f.seek(0x3c);f.write(bytes([len(n)])+n);f.close()"
	mv $(OBJ_DIR)/$(OUTPUT)_*.bin $(OBJ_DIR)/ 2>/dev/null || true

# Create directories if they don't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean test
