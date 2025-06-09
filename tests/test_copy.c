#include <cbytes.h>
#include "utils/log.c"

int test_copy() {    
    log_title("TESTING COPY FUNCTION");

    bytes_t name = "David";
    log_info("Original name: '%s'", name);
    byte_t name_copy[sizeof("David")];
    log_info("name_copy before copy: '%s'", name_copy);

    if (!copy(name, name_copy, sizeof(name_copy))) {
        log_err("Test 1 failed: '%s' '%s' copy failed", name, name_copy);
        return 1;
    }

    if (!equal(name, name_copy)) {
        log_err("Test 1 failed: name ('%s') isn't equal to name_copy ('%s')", name, name_copy);
        return 1;
    }

    log_ok("Test 1 passed: name ('%s') is equal to name_copy ('%s')", name, name_copy);

    log_title("TESTING COPY FUNCTION WITH ERROR");

    byte_t name_copy_err[] = "David ";
    log_info("name_copy_err before modification: '%s'", name_copy_err);
    if (!copy(name, name_copy_err, length(name_copy_err))) {
        log_err("Test 2 failed: '%s' '%s' copy failed", name, name_copy_err);
        return 1;
    }

    name_copy_err[5] = 'X'; // Simulate an error by adding an extra character
    log_info("name_copy_err after modification: '%s'", name_copy_err);

    if (equal(name, name_copy_err)) {
        log_err("Test 2 failed: name ('%s') is equal to name_copy_err ('%s')", name, name_copy_err);
        return 1;
    }

    log_ok("Test 2 passed: name ('%s') is not equal to name_copy_err ('%s')", name, name_copy_err);

    return 0;
}

#ifdef TEST_COPY
int main() {
    return test_copy();
}
#endif
