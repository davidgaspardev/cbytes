#include <stdio.h>

// Get length from a string (char array)
unsigned int length(const char * string) {
    unsigned int index = 0;

    while (*(string + index) != '\0') ++index;
    
    return index;
}

// Entry point, It is the point at which execution 
// of program is started
int main(unsigned int argc, const char ** argv) {

    // Create a char array (pointer)
    char * hello_world = "Hello World!";

    printf("%s (length: %u)\n\n", hello_world, length(hello_world));

    for(int i = 1; i < argc; i++) {
        printf("%s (length: %u)\n", argv[i], length(argv[i]));
    }

    return 1;
}