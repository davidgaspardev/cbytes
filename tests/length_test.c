#include <stdio.h>
#include "utils/log.c"
#include "../src/bytes.h"

void length_test(const char *data)
{
    log_title("TESTING LENGTH METHOD WITH ARGUMENT: %s", data);

    log_info("Getting length from '%s'", data);
    int data_len = length(data);

    logging_ok("  index: ");
    for (int i = 0; i < data_len; i++)
    {
        if (i > 0)
            printf(" | ");
        if (i == 9)
            printf(YEL " %i" RESET, i);
        else
            printf(YEL "%i" RESET, i);
    }

    log_breakline();
    logging_ok("   data: ");
    for (int i = 0; i < data_len; i++)
    {
        if (i > 0)
            printf(" | ");
        if (i < 9)
            printf(GRN "%c" RESET, data[i]);
        else
            printf(GRN " %c" RESET, data[i]);
    }

    log_breakline();
    logging_ok(" length: ");
    for (int i = 0; i < data_len; i++)
    {
        if (i > 0)
            printf(" | ");
        printf(CYN "%i" RESET, i + 1);
    }

    log_breakline();
}