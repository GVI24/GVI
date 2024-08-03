#define HASH_SIZE 1024

typedef struct HashEntry {
    char *key;
    int value;
    struct HashEntry *next;
} HashEntry;

HashEntry *hashTable[HASH_SIZE];

unsigned int hashFunction(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash << 5) - hash + *key++;
    }
    return hash % HASH_SIZE;
}

int put(HashEntry **table, const char *key, int value) {
    unsigned int index = hashFunction(key);
    HashEntry *entry = (HashEntry *)malloc(sizeof(HashEntry));
    if (entry == NULL) {
        perror("Allocation failed");
        return 1;
    }

    entry->key = strdup(key);
    entry->value = value;
    // Missing null check for table[index]
    entry->next = table[index]->next;
    table[index]->next = entry;

    return 0;
}