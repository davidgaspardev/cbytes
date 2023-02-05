NAME = bytes

CC = clang
CFLAGS = -c -Wall

BIN_DIRECTORY    = bin
LIB_DIRECTORY    = lib
BUILD_DIRECTORY  = build
SOURCE_DIRECTORY = src
TESTS_DIRECTORY  = tests
TMP_DIRECTORIES =    \
    $(BIN_DIRECTORY) \
    $(LIB_DIRECTORY) \
    $(BUILD_DIRECTORY)

SOURCES  = $(wildcard $(SOURCE_DIRECTORY)/*.c)
BUILDERS = $(patsubst $(SOURCE_DIRECTORY)/%.c, $(BUILD_DIRECTORY)/%.o, $(SOURCES))

HOST_ARCH_X64     = x64
HOST_ARCH_X86     = x86
HOST_ARCH_X86_64  = x86_64
HOST_ARCH_AMD64   = AMD64
HOST_ARCH_ARM64   = arm64
HOST_ARCH_ARMV7L  = armv7l
HOST_ARCH_ARMV7HF = armv7hf
HOST_ARCH_ARMV8   = armv8
HOST_ARCH_AARCH64 = aarch64
HOST_ARCH_ALL =       \
    HOST_ARCH_X64     \
    HOST_ARCH_X86     \
    HOST_ARCH_X86_64  \
    HOST_ARCH_AMD64   \
    HOST_ARCH_ARM64   \
    HOST_ARCH_ARMV7L  \
    HOST_ARCH_ARMV7HF \
    HOST_ARCH_ARMV8   \
    HOST_ARCH_AARCH64

# ---------------------------------------------------------------------
# Operating system and architecture detection
# ---------------------------------------------------------------------

ifeq ($(OS),Windows_NT)
    PLATFORM = win32

    # Detect architecture
    ifeq ($(PROCESSOR_ARCHITEW6432),$(HOST_ARCH_AMD64))
        HOST_ARCH = $(HOST_ARCH_X64)
    else 
        ifeq ($(PROCESSOR_ARQUITECTURE),$(HOST_ARCH_AMD64))
            HOST_ARCH = $(HOST_ARCH_X64)
        endif
        ifeq ($(PROCESSOR_ARQUITECTURE, $(HOST_ARCH_X86)))
            HOST_ARCH = $(HOST_ARCH_X86)
        endif
    endif
else 
    ifeq ($(shell uname -s),Linux)
        PLATFORM = Linux

        # Detect architecture
        ifeq ($(shell uname -m),$(HOST_ARCH_X86_64))
            HOST_ARCH = $(HOST_ARCH_X64)
        endif
        ifeq ($(filter %86,$(shell uname -m)),)
            HOST_ARCH = $(HOST_ARCH_X86)
        endif
        ifeq ($(shell uname -m),$(HOST_ARCH_ARMV7L))
            HOST_ARCH = $(HOST_ARCH_ARMV7HF)
        endif
        ifneq (,$(filter $(HOST_ARCH_AARCH64) $(HOST_ARCH_ARMV8) $(HOST_ARCH_ARM64), $(shell uname -m)))
            HOST_ARCH = $(HOST_ARCH_AARCH64)
        endif
    endif
    ifeq ($(shell uname -s),Darwin)
        PLATFORM = Darwin

        # Detect architecture
        ifeq ($(shell uname -m),$(HOST_ARCH_X86_64))
            HOST_ARCH = $(HOST_ARCH_X64)
        endif
        ifeq ($(shell uname -m), $(HOST_ARCH_ARM64))
            HOST_ARCH = $(HOST_ARCH_AARCH64)
        endif
    endif
endif

ifndef PLATFORM
$(error We could not detect your host platform)
endif
ifndef HOST_ARCH
$(error We could not detect your host architecture)
endif

TARGETS = \
    test \
    library \
    help \
    info \
    clean 

.PHONY: $(TARGETS)

test: $(BIN_DIRECTORY) library
	$(CC) $(TESTS_DIRECTORY)/main.c -o $(BIN_DIRECTORY)/test -L$(LIB_DIRECTORY) -lbytes

library: $(LIB_DIRECTORY) $(BUILDERS)
	@ar -rc $(LIB_DIRECTORY)/lib$(NAME).a $(BUILD_DIRECTORY)/$(NAME).o
	@echo "[ OK ] Static library file created ($(LIB_DIRECTORY)/lib$(NAME).a)"

help:
	@echo "Available targets: $(TARGETS)"

info:
	@echo "Plataform: $(PLATFORM)"
	@echo "Host arch: $(HOST_ARCH)"

clean:
	$(foreach dir, $(TMP_DIRECTORIES), $(shell rm -rf $(dir)))
	@echo "[ OK ] Removed directories if they existed: $(TMP_DIRECTORIES)"

$(BUILD_DIRECTORY):
	@mkdir -p $@

$(BIN_DIRECTORY):
	@mkdir -p $@

$(LIB_DIRECTORY):
	@mkdir -p $@

$(BUILD_DIRECTORY)/%.o: $(BUILD_DIRECTORY) $(SOURCE_DIRECTORY)/%.c
	$(CC) $(CFLAGS) $(word 2, $^) -o $@

