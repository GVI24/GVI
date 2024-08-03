// Vulnerability: Memory corruption and unchecked memory allocation.
int expandHashTable(HashTable *hashTable) {
    unsigned int newSize = hashTable->size * 2; // No check for overflow.
    HashEntry *newEntries = (HashEntry *)calloc(newSize, sizeof(HashEntry)); // Unchecked allocation.

    if (newEntries == NULL) {
        return -1; // Allocation failure not properly handled.
    }

    // Rehashing the old entries into the new table, but without checking for hash collisions.
    for (unsigned int i = 0; i < hashTable->size; ++i) {
        if (hashTable->entries[i].used) {
            unsigned int newIndex = hash(hashTable->entries[i].key) % newSize;
            newEntries[newIndex] = hashTable->entries[i];
        }
    }

    free(hashTable->entries); // Previous entries freed, potential use-after-free if not managed correctly.
    hashTable->entries = newEntries;
    hashTable->size = newSize;

    return 0;
}