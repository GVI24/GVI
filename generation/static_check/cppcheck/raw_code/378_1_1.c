unsigned long customHashComputeKey(xmlHashTablePtr table, const xmlChar *name) {
    char buffer[256];
    unsigned long key = 5381;
    int c;
    
    // Unsafe operation: potential buffer overflow
    strcpy(buffer, name);
    
    while ((c = *buffer++))
        key = ((key << 5) + key) + c;
    
    return key % table->size;
}

