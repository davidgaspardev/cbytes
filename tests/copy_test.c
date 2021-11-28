#include <stdio.h>
#include "utils/log.c"
#include "../src/string.h"

void copy_test(const char *data)
{
    log_title("TESTING COPY METHODS WITH ARGUMENT: %s", data);

    int full_len = length(data);
    char data_full_copy[full_len];

    log_info("Copying the characters of the '%s' string to the data_copy variable", data);

    if (copy(data, data_full_copy, sizeof(data_full_copy)) > -1)
    {
        log_ok("data: %s", data);
        log_ok("data_copy: " YEL "%s" RESET, data_full_copy);
    }
    else
    {
        log_err("something wrong with subcopy method");
    }

    log_title("TESTING COPY METHODS WITH ARGUMENT: %s", data);

    int len = length(data) / 2;
    char data_copy[len];

    log_info("Copying the first %i characters of the '%s' string to the data_copy variable", len, data);

    if (subcopy_len(data, len, data_copy, sizeof(data_copy)) > -1)
    {
        log_ok("data: %s", data);
        log_ok("data_copy: " YEL "%s" RESET, data_copy);
    }
    else
    {
        log_err("something wrong with subcopy method");
    }

    int start_index = len / 2;

    log_info("Copying the first %i characters of the '%s' string after the %iº character to the data_copy variable", len, data, start_index);
    if (subcopy_index_len(data, start_index, len, data_copy, sizeof(data_copy)) > -1)
    {
        log_ok("data: %s", data);
        log_ok("data_copy: " YEL "%s" RESET, data_copy);
    }
    else
    {
        log_err("something wrong with subcopy_index_length method");
    }
}