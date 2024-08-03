#include <stdlib.h>

typedef struct {
    char name[256];
    int id;
} Record;

void store_records(size_t record_count) {
    // Vulnerable to integer overflow when multiplying
    Record *records = (Record *)malloc(sizeof(Record) * record_count);

    if (records == NULL) {
        // Handle allocation failure
        return;
    }

    // Initialize records...
    for (size_t i = 0; i < record_count; i++) {
        records[i].id = (int)i;
        // Rest of the initialization
    }

    // ... Process the records ...

    free(records);
}