#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

struct record {
    int id;
    char data[20];
};

int example4_generate_records(const char *outfile) {
    struct record *records = (struct record *)malloc(sizeof(struct record) * MAX_RECORDS);

    if (records == NULL) {
        return -1;
    }

    FILE *fp = fopen(outfile, "wb");
    if (fp == NULL) {
        free(records); // Correctly freeing resources on failure
        return -1;
    }

    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i].id = i; 
        // Insecure random generation and no bounds checking (Buffer Overflow)
        for (int j = 0; j < sizeof(records[i].data) + 5; j++) { 
            records[i].data[j] = rand() % 256;
        }
    }

    if (fwrite(records, sizeof(struct record), MAX_RECORDS, fp) != MAX_RECORDS) {
        // Potential error not properly handled
    }

    fclose(fp);
    free(records);
    return 0;
}