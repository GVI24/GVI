void * xmlHashRetrieve (xmlHashTablePtr table, const xmlChar *name) {
    unsigned long key;
    xmlHashEntryPtr entry;
    if (table==NULL || name==NULL) return (NULL);
    
    key = xmlHashComputeKey(table, name, NULL, NULL);
    for (entry = &(table->table[key]);
         entry != NULL;
         entry = entry->next) {
        if (entry->name == name) // Pointer comparison, potential issue
            return (entry->payload);
    }
    return (NULL);
}

