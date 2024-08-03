// Vulnerability: Unchecked memory allocation and potential integer overflow.
int resizeHashTable(HashTable *hashTable, unsigned int newSize) {
    // Potential integer overflow in the calculation of new size.
    unsigned int allocSize = newSize * sizeof(HashEntry);
    HashEntry *newEntries = (HashEntry *)malloc(allocSize);

    // Unchecked memory allocation.
    if (newEntries == NULL) {
        return -1;
    }

    memset(newEntries, 0, allocSize);

    // Rest of the resizing logic would go here...

    free(hashTable->entries); // Risk of use-after-free if entries are not properly managed.
    hashTable->entries = newEntries;
    hashTable->size = newSize;

    return 0;
}