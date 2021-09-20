BIN_DIRECTORY ?= bin
BUILD_DIRECTORY = build
SOURCE_DIRECTORY = src
TESTS_DIRECTORY = tests

TEST ?= main

CC = clang

# ---------------------------------------------------------------------
# Operating system and architecture detection
# ---------------------------------------------------------------------

ifeq ($(OS),Windows_NT)
    PLATFORM = win32

    # Detect architecture
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        HOST_ARCH = x64
    else 
        ifeq ($(PROCESSOR_ARQUITECTURE),AMD64)
            HOST_ARCH = x64
        endif
        ifeq ($(PROCESSOR_ARQUITECTURE, x86))
            HOST_ARCH = x86
        endif
    endif
else 
    ifeq ($(shell uname -s),Linux)
        PLATFORM = Linux

        # Detect architecture
        ifeq ($(shell uname -m,x86_64))
            HOST_ARCH = x64
        endif
        ifeq ($(filter %86,$(shell uname -m)),)
            HOST_ARCH = x86
        endif
        ifeq ($(shell uname -m),armv7l)
            HOST_ARCH = armv7hf
        endif
        ifeq ($(shell uname -m),aarch64)
            HOST_ARCH = aarch64
        endif
        ifeq ($(shell uname -m),armv8)
            HOST_ARCH = aarch64
        endif
        ifeq ($(shell uname -m),arm64)
            HOST_ARCH = aarch64
        endif
    endif
    ifeq ($(shell uname -s),Darwin)
        PLATFORM = Darwin

        # Detect architecture
        ifeq ($(shell uname -m),x86_64)
            HOST_ARCH = x64
        endif
        ifeq ($(shell uname -m), arm64)
            HOST_ARCH = aarch64
        endif
    endif
endif

ifndef PLATFORM
$(error We could not detect your host platform)
endif
ifndef HOST_ARCH
$(error We could not detect your host architecture)
endif

TARGETS: help info clean string.o

.PRONY: $(TARGETS)

all: main.o string.o
	$(CC) -o test $(BUILD_DIRECTORY)/string.o $(BUILD_DIRECTORY)/main.o
	@echo "Success"

test: string.o
	$(CC) -c $(TESTS_DIRECTORY)/$(TEST).c -o $(BUILD_DIRECTORY)/test.o
	@mkdir -p $(BIN_DIRECTORY)
	$(CC) -o $(BIN_DIRECTORY)/test $(BUILD_DIRECTORY)/string.o $(BUILD_DIRECTORY)/test.o 

help:
	@echo "Available targets: $(TARGETS)"

info:
	@echo "Plataform: $(PLATFORM)"
	@echo "Host arch: $(HOST_ARCH)"

clean:
	rm -rf $(BUILD_DIRECTORY)
	rm -rf $(BIN_DIRECTORY)

main.o: string.o
	$(CC) -c $(SOURCE_DIRECTORY)/main.c -o $(BUILD_DIRECTORY)/main.o

string.o:
	@mkdir -p $(BUILD_DIRECTORY)
	$(CC) -c $(SOURCE_DIRECTORY)/string.c -o $(BUILD_DIRECTORY)/string.o