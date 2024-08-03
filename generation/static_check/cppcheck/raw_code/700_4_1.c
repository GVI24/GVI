#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save_to_file(char *filename, char *data) {
    char file_path[256];
    
    // Vulnerable to buffer overflow due to concatenation without bounds checking
    sprintf(file_path, "/var/log/myapp/%s", filename);
    
    // Write data to file...
    printf("Data will be saved to: %s\n", file_path);
}