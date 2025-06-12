#include <cbytes.h>
#include "utils/log.c"

int test_equal() {
    char *data1 = "Hello, World!";
    char *data2 = "Hello, World!";
    char *data3 = "Goodbye, World!";
    char *data4 = "Hello, Universe!";
    char *data5 = "David";
    char *data6 = "david";

    log_title("TESTING EQUAL FUNCTION");

    // Test equal function
    if (equal(data1, data2)) {
        log_ok("Test 1 passed: '%s' and '%s' are equal", data1, data2);
    } else {
        log_err("Test 1 failed: '%s' and '%s' are not equal", data1, data2);
        return 1; // Exit with error
    }

    if (!equal(data1, data3)) {
        log_ok("Test 2 passed: '%s' and '%s' are not equal", data1, data3);
    } else {
        log_err("Test 2 failed: '%s' and '%s' are equal", data1, data3);
        return 1; // Exit with error
    }

    if (!equal(data1, data4)) {
        log_ok("Test 3 passed: '%s' and '%s' are not equal", data1, data4);
    } else {
        log_err("Test 3 failed: '%s' and '%s' are equal", data1, data4);
        return 1; // Exit with error
    }

    if (!equal(data5, data6)) {
        log_ok("Test 4 passed: '%s' and '%s' are not equal", data5, data6);
    } else {
        log_err("Test 4 failed: '%s' and '%s' are equal", data5, data6);
        return 1; // Exit with error
    }

    return 0; // All tests passed
}