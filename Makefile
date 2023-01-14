BIN_DIRECTORY    = bin
LIB_DIRECTORY    = lib
BUILD_DIRECTORY  = build
SOURCE_DIRECTORY = src
TESTS_DIRECTORY  = tests

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
    dirs \
    lib \
    help \
    info \
    clean \
    test.o \
    string.o

.PHONY: $(TARGETS)

test: string.o test.o
	@mkdir -p $(BIN_DIRECTORY)
	$(CC) -o $(BIN_DIRECTORY)/test $(BUILD_DIRECTORY)/string.o $(BUILD_DIRECTORY)/test.o

dirs:
	@mkdir -p $(LIB_DIRECTORY)
	@mkdir -p $(BUILD_DIRECTORY)
	@mkdir -p $(BIN_DIRECTORY)

lib: dirs string.o
	@ar -rc $(LIB_DIRECTORY)/libstring.a $(BUILD_DIRECTORY)/string.o
	@echo "[ OK ] Static library file created ($(LIB_DIRECTORY)/libstring.a)"

help:
	@echo "Available targets: $(TARGETS)"

info:
	@echo "Plataform: $(PLATFORM)"
	@echo "Host arch: $(HOST_ARCH)"

clean:
	rm -rf $(BUILD_DIRECTORY)
	rm -rf $(BIN_DIRECTORY)
	rm -rf $(LIB_DIRECTORY)

test.o: dirs
	@$(CC) -c $(TESTS_DIRECTORY)/main.c -o $(BUILD_DIRECTORY)/test.o
	@echo "[ OK ] Test object file created ($(BUILD_DIRECTORY)/test.o)"

string.o: dirs
	@$(CC) -c $(SOURCE_DIRECTORY)/string.c -o $(BUILD_DIRECTORY)/string.o
	@echo "[ OK ] String object file created ($(BUILD_DIRECTORY)/string.o)"