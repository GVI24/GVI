typedef struct {
    int id;
    char data[20];
} Record;

void processRecords(Record *records, int recordCount) {
    Record *rec = records;
    for (int i = 0; i < recordCount; i++) {
        printf("%d: %s\n", rec->id, rec->data);
        rec++; // Vulnerability: no check if 'rec' goes past 'records + recordCount'
    }
}

