#include <stdio.h>
#include <stdarg.h>

#ifndef _LOG_C
#define _LOG_C

/// https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
#define RED "\x1B[31m"  // red
#define GRN "\x1B[32m"  // green
#define YEL "\x1B[33m"  // yellow
#define BLU "\x1B[34m"  // blue
#define MAG "\x1B[35m"  // magenta
#define CYN "\x1B[36m"  // cyan
#define WHT "\x1B[37m"  // white
#define RESET "\x1B[0m" // reset color
// #define KNRM  "\x1B[0m"
// #define KRED  "\x1B[31m"
// #define KGRN  "\x1B[32m"
// #define KYEL  "\x1B[33m"
// #define KBLU  "\x1B[34m"
// #define KMAG  "\x1B[35m"
// #define KCYN  "\x1B[36m"
// #define KWHT  "\x1B[37m"

void log_breakline()
{
    printf("\n");
}

void logging_title(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    // Break line
    log_breakline();

    printf(CYN "[ TITLE ] ==> " RESET);
    vprintf(msg, arguments);
}

void log_title(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    // Break line
    log_breakline();

    printf(CYN "[ TITLE ] ==> " RESET);
    vprintf(msg, arguments);

    // Break line
    log_breakline();
}

void logging_info(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    printf(BLU "[ INFO  ] " RESET);
    vprintf(msg, arguments);
}

void log_info(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    printf(BLU "[ INFO  ] " RESET);
    vprintf(msg, arguments);

    // Break line
    log_breakline();
}

void logging_ok(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    printf(GRN "[ OK    ] " RESET);
    vprintf(msg, arguments);
}

void log_ok(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    printf(GRN "[ OK    ] " RESET);
    vprintf(msg, arguments);

    // Break line
    log_breakline();
}

void logging_err(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    printf(RED "[ ERROR ]" RESET);
    vprintf(msg, arguments);
}

void log_err(const char *msg, ...)
{
    va_list arguments;
    va_start(arguments, msg);

    printf(RED "[ ERROR ]" RESET);
    vprintf(msg, arguments);

    // Break line
    log_breakline();
}

#endif