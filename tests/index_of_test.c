#include <stdio.h>
#include <cbytes.h>
#include "utils/log.c"

void insert_lookup_string(char *chars);

void index_of_test(const char *data)
{
    log_title("TESTING \"INDEX OF\" FUNCTION WITH THIS ARGUMENT: %s", data);

    // Getting lookup string
    char lookup[100];
    logging_info("You who find the index of what in this string (%s): ", data);
    insert_lookup_string(lookup);

    log_info("Looking for index from string: '%s'", lookup);
    log_info("Running 'index_of' function with these arguments: \"%s\", \"%s\")", data, lookup);
    int result = index_of(data, lookup);
    if (result > -1)
    {
        log_ok("Index found: %d (%c)", result, data[result]);
    }
    else
    {
        log_ok("\"%s\" not found in the \"%s\"", lookup, data);
    }
}

void insert_lookup_string(char *chars)
{
    scanf("%[^\n]s", chars);
    fflush(stdin);
}