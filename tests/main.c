#include <stdio.h>
#include <cbytes.h>
#include "copy_test.c"
#include "length_test.c"
#include "index_of_test.c"
#include "test_equal.c"
#include "test_copy.c"

// Entry point, It is the point at which execution
// of program is started
int main(int argc, const char **argv)
{
    if (test_equal()) return 1;
    if (test_copy()) return 1;
    
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            copy_test(argv[i]);
            length_test(argv[i]);
            index_of_test(argv[i]);
        }
    }

    else
        printf("You must enter the arguments to perform the tests\n");

    return 0;
}