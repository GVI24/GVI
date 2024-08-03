// Vulnerability: Use-after-free and unchecked memory allocation.
void deleteKey(HashTable *hashTable, const char *key) {
    unsigned int index = hash(key) % hashTable->size;
    HashEntry *entry = hashTable->entries[index];
    HashEntry *prev = NULL;

    // Traverse linked list to find the entry.
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            if (prev != NULL) {
                prev->next = entry->next;
            } else {
                hashTable->entries[index] = entry->next;
            }

            free(entry->key); // Entry key freed.

            // Entry freed without nullifying pointer in the array ('entry->next').
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}