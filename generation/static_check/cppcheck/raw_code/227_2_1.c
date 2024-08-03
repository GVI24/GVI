#include <stdlib.h>

typedef struct {
    unsigned int index;
    int value;
} Record;

void updateRecord(Record *records, unsigned int size, unsigned int index, int newValue) {
    // Vulnerable: No check to ensure index is within bounds of records array
    records[index].value = newValue; // Write-what-where condition if index is out of bounds
}

int main() {
    Record records[10];
    // Calling the function with an out-of-bounds index leads to arbitrary memory write
    updateRecord(records, 10, 20, 12345);
    return 0;
}