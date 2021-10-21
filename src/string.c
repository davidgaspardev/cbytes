#include "string.h"

// Get argument length
unsigned int length(const char * arg) {
    unsigned int offset = 0;
    unsigned int count = 0;

    while (*(arg + offset) != '\0') {
        ++offset;
        ++count;
    }

    return count;
}

// Check that the values of two string (char *) are equal.
unsigned int equal(const char * data_1, const char * data_2) {
    unsigned int data_1_length = length(data_1);
    unsigned int data_2_length = length(data_2);

    if(data_1_length != data_2_length) return FALSE;

    for(int i = 0; i < data_1_length; i++) {
        if(data_1[i] != data_2[i]) return FALSE;
    }

    return TRUE;
}

// Copy data from the source argument to the target argument
//
// Impotant: destination needs to be declared as "char [n]", because if 
// it is declared as "char *", it will not be possible to modify the data.
// char * is a literal string read-only declaration.
void copy(const char * source, char * destination, size_t sizeof_destination) {
    unsigned int source_length = length(source);

    if(source_length > sizeof_destination) {
        printf("[ insufficient defined memory ]: %u (%s) > %zu (%s) - It's dangerous to invade memory \n", source_length, source, sizeof_destination, destination);
        return;
    }

    for(int i = 0; i < (source_length + 1); i++) {
        *(destination + i) = source[i];
    }

    *(destination + source_length) = '\0';
}

// subcopy method
// if the function returns -1 it means that the start_index variable is greater than the end_index variable.
int subcopy(const char * src, int start_index, int end_index, char * dest,  size_t sizeof_dest) {
    // Check if the initial index exceeds the final index.
    if(start_index > end_index) return -1;

    // Check if the index exceeds the length of the string to be copied (source).
    // If it exceeds, update index to the last index of the string to be copied.
    unsigned int src_length = length(src);
    if(end_index >= src_length) end_index = (src_length - 1);

    // Check if the index exceeds the length of the string to be pasted (destination).
    // If it exceeds, update index to the last index of the string to be pasted.
    // if(end_index >= sizeof_dest) end_index = (sizeof_dest - 1);

    // calculation of total length of final string (destination).
    unsigned int dest_length = (end_index + 1) - start_index;

    if(dest_length > sizeof_dest) dest_length = sizeof_dest;

    for(int i = 0; i < dest_length; i++) dest[i] = *(src + start_index + i);

    dest[dest_length] = '\0';

    return 1;
}

int subcopy_len(const char * src, unsigned int dest_len, char * dest, size_t sizeof_dest) {
    return subcopy(src, 0, (dest_len - 1), dest, sizeof_dest);
}

int subcopy_index_len(const char * src, unsigned int start_index, unsigned int dest_len, char * dest, size_t sizeof_dest) {
    return subcopy(src, start_index, ((start_index + dest_len) - 1), dest, sizeof_dest);
}