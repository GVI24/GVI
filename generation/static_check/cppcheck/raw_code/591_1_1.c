#include <limits.h>

void integer_overflow_example(unsigned int a, unsigned int b) {
    unsigned int result = a * b;
    if (a != 0 && result / a != b) {
        // Handle overflow, but the check itself is after the overflow has occurred
        printf("Overflow detected\n");
    } else {
        printf("Result is: %u\n", result);
    }
}