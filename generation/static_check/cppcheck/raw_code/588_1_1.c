#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

int example2_process_file(const char *input, const char *output) {
    FILE *in = fopen(input, "r"), *out = NULL;
    if (in == NULL) {
        return -1; // fopen failed, in is NULL
    }
    
    // Allocation for output buffer, but if fopen fails for the output file,
    // allocated memory is not freed (Resource Leak)
    char *out_buf = (char *)malloc(SIZE); 

    out = fopen(output, "w");
    if (out == NULL) {
        fclose(in); // Only in is correctly closed
        // Resource Leak: out_buf is not freed
        return -1;
    }

    // Buffer Overflow: Reads SIZE + 1 bytes into a SIZE byte buffer
    while (fread(out_buf, 1, SIZE + 1, in) == SIZE + 1) { 
        fwrite(out_buf, 1, SIZE, out); // Only writes SIZE bytes
    }

    fclose(in);
    fclose(out);
    free(out_buf);
    return 0;
}