# Makefile for Snake & Ladder Game (Modernized Version)

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Libraries
LIBS = -lSDL2 -lSDL2_ttf

# Source files
SRC = snake_ladder_modern.c
TARGET = snake_ladder_modern

# Default target
all: $(TARGET)

# Build the modernized version
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

# Build the original version (requires Turbo C or DOS emulator)
original: snake&ladder.c
	@echo "Original version requires Turbo C or DOS emulator"
	@echo "Use: tcc snake&ladder.c"

# Install dependencies (macOS)
install-deps-mac:
	brew install sdl2 sdl2_ttf

# Install dependencies (Ubuntu/Debian)
install-deps-ubuntu:
	sudo apt-get update
	sudo apt-get install libsdl2-dev libsdl2-ttf-dev

# Install dependencies (CentOS/RHEL)
install-deps-centos:
	sudo yum install SDL2-devel SDL2_ttf-devel

# Clean build files
clean:
	rm -f $(TARGET)

# Run the modernized game
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build the modernized version"
	@echo "  original     - Show info about original version"
	@echo "  install-deps-mac    - Install dependencies on macOS"
	@echo "  install-deps-ubuntu - Install dependencies on Ubuntu/Debian"
	@echo "  install-deps-centos - Install dependencies on CentOS/RHEL"
	@echo "  clean        - Remove build files"
	@echo "  run          - Build and run the modernized game"
	@echo "  help         - Show this help message"

.PHONY: all original install-deps-mac install-deps-ubuntu install-deps-centos clean run help
