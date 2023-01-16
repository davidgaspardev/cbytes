NAME = bytes

BIN_DIRECTORY    = bin
LIB_DIRECTORY    = lib
BUILD_DIRECTORY  = build
SOURCE_DIRECTORY = src
TESTS_DIRECTORY  = tests

TMP_DIRECTORIES = \
    $(BIN_DIRECTORY) \
    $(LIB_DIRECTORY) \
    $(BUILD_DIRECTORY)

CC = clang
CFLAGS = -c -Wall

SOURCES  = $(wildcard $(SOURCE_DIRECTORY)/*.c)

BUILDERS = $(patsubst $(SOURCE_DIRECTORY)/%.c, $(BUILD_DIRECTORY)/%.o, $(SOURCES))

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
        ifeq ($(shell uname -m),x86_64)
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

TARGETS = \
    test \
    library \
    help \
    info \
    clean 

.PHONY: $(TARGETS)

test: $(BIN_DIRECTORY) $(BUILDERS)
	$(CC) $(TESTS_DIRECTORY)/main.c $(BUILDERS) -o $(BIN_DIRECTORY)/test

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

