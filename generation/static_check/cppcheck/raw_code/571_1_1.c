static unsigned int calculateHashValue(xmlHashTablePtr table, const char *key) {
    unsigned int hash = 5381;
    int c;
    
    if (table == NULL) // Improperly checked, should return or handle the error.
        printf("Table is NULL.\n"); // Vulnerable to NULL dereference later.

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % table->size; // No check for zero table->size.
}

