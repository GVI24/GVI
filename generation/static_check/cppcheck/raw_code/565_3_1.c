#include <stdlib.h>
#include <string.h>

#define MAX_STRUCTS 128

typedef struct {
    int id;
    char name[50];
} Record;

int process_records(int num_records, Record *records) {
    Record *record_buffer;
    
    // Calculate required buffer size
    size_t required_size = num_records * sizeof(Record);
    
    // Vulnerability: Buffer could be too small if num_records is large
    record_buffer = malloc(MAX(MAX_STRUCTS * sizeof(Record), required_size));
    
    // Potential overflow if num_records exceeds MAX_STRUCTS
    memcpy(record_buffer, records, required_size);
    
    // Process record_buffer...
    
    free(record_buffer);
    return 0;
}