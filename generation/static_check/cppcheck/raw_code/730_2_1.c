// Vulnerability: Potential use-after-free and memory leak.
int removeEntries(HashTable *hashTable) {
    for (unsigned int i = 0; i < hashTable->size; ++i) {
        HashEntry *current = hashTable->entries[i];
        while (current != NULL) {
            HashEntry *temp = current;
            current = current->next;
            free(temp->key); // Key memory freed.

            // Memory for 'temp' is freed, but 'current' might still be used afterward.
            free(temp);
        }
    }

    // The table's entries have been individually freed, but the array itself is not set to NULL.
    // This may lead to a use-after-free error if accessed later on.
    return 0;
}