// Example 2: A function to update an array of structures by a user-defined update function
typedef struct {
    char *data;
    int key;
} Record;

void update_records(Record *records, int n, void (*update_func)(Record *)) {
    for (int i = 0; i < n; ++i) {
        update_func(&records[i]); // Vulnerable: update_func might free records[i].data
        // If data is freed inside update_func, records[i].data becomes a dangling pointer
        printf("Updated record %d: %s\n", records[i].key, records[i].data); // Vulnerable: use-after-free if data is freed
    }
}