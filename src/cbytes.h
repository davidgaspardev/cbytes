/*
 * Bytes library
 * Author: David Gaspar <davidgaspar.dev@gmail.com>
 */
#ifndef CBYTES_H_
#define CBYTES_H_

typedef char          byte_t;
typedef unsigned char ubyte_t;
typedef char *        bytes_t;
typedef const char *  cbytes_t;

#ifndef bool
#define true (ubyte_t)1
#define false (ubyte_t)0
#endif

unsigned int length(cbytes_t arg);

int index_of(
    cbytes_t target,
    cbytes_t fragment
);

ubyte_t equal(
    cbytes_t bytes_1,
    cbytes_t bytes_2
);

byte_t copy(
    cbytes_t      src,
    bytes_t       dst,
    unsigned long sizeof_dst
);

byte_t subcopy(
    cbytes_t      src,
    unsigned int  start_index,
    unsigned int  end_index,
    bytes_t       dst,
    unsigned long sizeof_dst
);

byte_t subcopy_len(
    cbytes_t      src,
    unsigned int  dst_length,
    bytes_t       dst,
    unsigned long sizeof_dst
);

byte_t subcopy_index_len(
    cbytes_t      src,
    unsigned int  start_index,
    unsigned int  dst_length,
    bytes_t       dst,
    unsigned long sizeof_dst
);

#endif