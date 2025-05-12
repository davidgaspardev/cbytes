/*
 * My library for string
 * Author: David Gaspar <davidgaspar.dev@gmail.com>
 */
#include "bytes.h"

// Get argument length
unsigned int length(cbytes_t arg)
{
    unsigned int offset = 0;
    unsigned int count = 0;

    while (*(arg + offset) != '\0') {
        ++offset;
        ++count;
    }

    return count;
}

// Check that the values of two string (bytes_t ) are equal.
ubyte_t equal(cbytes_t bytes_1, cbytes_t bytes_2)
{
    unsigned int bytes_1_length = length(bytes_1);
    unsigned int bytes_2_length = length(bytes_2);

    if (bytes_1_length != bytes_2_length) {
        return false;
    }

    for (int i = 0; i < bytes_1_length; i++) {
        if (bytes_1[i] != bytes_2[i])
            return false;
    }

    return true;
}

// Copy data from the source argument to the target argument
//
// Impotant: destination needs to be declared as "byte_t [n]", because if
// it is declared as "bytes_t ", it will not be possible to modify the data.
// bytes_t  is a literal string read-only declaration.
byte_t copy(cbytes_t source, bytes_t destination, unsigned long sizeof_destination)
{
    unsigned int source_length = length(source);

    if (source_length > sizeof_destination) {
        return -1;
    }

    for (int i = 0; i < source_length; i++) {
        destination[i] = source[i];
    }

    destination[source_length] = '\0';

    return 1;
}

// subcopy method
// if the function returns -1 it means that the start_index variable is greater than the end_index variable.
byte_t subcopy(cbytes_t src, unsigned int start_index, unsigned int end_index, bytes_t dest, unsigned long sizeof_dest)
{
    // Check if the initial index exceeds the final index.
    if (start_index > end_index)
        return -1;

    // Check if the index exceeds the length of the string to be copied (source).
    // If it exceeds, update index to the last index of the string to be copied.
    unsigned int src_length = length(src);
    if (end_index >= src_length)
        end_index = (src_length - 1);

    // Check if the index exceeds the length of the string to be pasted (destination).
    // If it exceeds, update index to the last index of the string to be pasted.
    // if(end_index >= sizeof_dest) end_index = (sizeof_dest - 1);

    // calculation of total length of final string (destination).
    unsigned int dest_length = (end_index + 1) - start_index;

    if (dest_length > sizeof_dest)
        dest_length = sizeof_dest;

    for (int i = 0; i < dest_length; i++)
        dest[i] = *(src + start_index + i);

    dest[dest_length] = '\0';

    return 1;
}

byte_t subcopy_len(cbytes_t src, unsigned int dest_len, bytes_t dest, unsigned long sizeof_dest)
{
    return subcopy(src, 0, (dest_len - 1), dest, sizeof_dest);
}

byte_t subcopy_index_len(cbytes_t src, unsigned int start_index, unsigned int dest_len, bytes_t dest, unsigned long sizeof_dest)
{
    return subcopy(src, start_index, ((start_index + dest_len) - 1), dest, sizeof_dest);
}

int index_of(cbytes_t target, cbytes_t fragment)
{
    int result = -1;
    int target_len = length(target);
    int fragment_len = length(fragment);

    if (fragment_len > target_len) {
        return -1;
    }

    if (fragment_len == target_len) {
        if (equal(target, fragment)) {
            return 0;
        }
        return -1;
    }

    int i, j = 0;
    for (i = 0; i < target_len; i++) {
        if(target[i] == fragment[j]) {
            result = i;

            for (; j < fragment_len; j++) {
                if(target[i+j] != fragment[j]) {
                    result = -1;
                    j = 0;
                    break;
                }
            }

            if (result != -1) {
                return result;
            }
        }
    }

    return -1;
}