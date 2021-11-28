/*
 * My library for string
 * Author: David Gaspar <davidgaspar.dev@gmail.com>
 */
#ifndef _STRING_H_
#define _STRING_H_

#include <stdio.h>

#define FALSE 0
#define TRUE 1

unsigned int length(const char *arg);
unsigned int equal(const char *data_1, const char *data_2);
int copy(const char *source, char *destination, size_t sizeof_destination);
int subcopy(const char *source, int start_index, int end_index, char *destination, size_t sizeof_destination);
int subcopy_len(const char *src, unsigned int dest_length, char *dest, size_t sizeof_dest);
int subcopy_index_len(const char *src, unsigned int start_index, unsigned int dest_length, char *dest, size_t sizeof_dest);

#endif