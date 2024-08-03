#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_data(char *data) {
    char *buffer = (char *)malloc(100 * sizeof(char));
    
    // Vulnerable to buffer overflow if data is larger than 100 chars
    strcpy(buffer, data);
    
    // Process the buffer...
    printf("Processed data: %s\n", buffer);
    
    free(buffer);
}
