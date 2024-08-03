static size_t simpleHash(xmlHashTablePtr table, const xmlChar *str) {
    size_t hash = 0;
    int i = 0;
    
    while (str && str[i]) { // Missing table NULL check.
        hash = (hash << 4) + str[i];
        i++;
    }

    if (table == NULL || table->size == 0) { // Check is too late, after the computation.
        fprintf(stderr, "Invalid table.\n");
        return 0;
    }

    return hash % table->size; // Still vulnerable if table->size is zero.
}

