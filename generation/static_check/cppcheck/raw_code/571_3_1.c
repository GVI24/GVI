static unsigned long myHashCalculator(xmlHashTablePtr table, const xmlChar *key, const xmlChar *value) {
    unsigned long hash = 0;
    if (!key || !value) // Missing check for table.
        return 0;

    while (*key) {
        hash = (hash * 1653) ^ (unsigned long)(*key++);
    }

    while (*value) {
        hash = (hash * 1621) ^ (unsigned long)(*value++);
    }

    // Unsafe division, might cause division by zero if table->size is not properly initialized.
    return hash % table->size; 
}