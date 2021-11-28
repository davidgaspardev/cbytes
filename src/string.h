/*
 * My library for string
 * Author: David Gaspar <davidgaspar.dev@gmail.com>
 */
#ifndef _STRING_H_
#define _STRING_H_

typedef unsigned long size_t;
typedef unsigned int uint_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;

#ifndef bool
#define true (uint8_t)1
#define false (uint8_t)0
#endif

uint_t length(const char *arg);
uint8_t equal(const char *data_1, const char *data_2);
int8_t copy(const char *source, char *destination, size_t sizeof_destination);
int8_t subcopy(const char *source, int start_index, int end_index, char *destination, size_t sizeof_destination);
int8_t subcopy_len(const char *src, unsigned int dest_length, char *dest, size_t sizeof_dest);
int8_t subcopy_index_len(const char *src, unsigned int start_index, unsigned int dest_length, char *dest, size_t sizeof_dest);
int index_of(const char *target, const char *fragment);

#endif