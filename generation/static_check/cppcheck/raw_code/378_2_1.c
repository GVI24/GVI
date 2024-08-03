void * xmlHashFind(xmlHashTablePtr table, const xmlChar *name) {
    if (table == NULL || name == NULL) return (NULL);

    unsigned long key = customHashComputeKey(table, name);
    xmlHashEntryPtr entry = &(table->table[key]);
    
    while (entry != NULL) {
        // One comparison uses xmlStrEqual, the other uses direct pointer comparison
        if (xmlStrEqual(entry->name, name) && (entry->name2 == name))
            return (entry->payload);
        entry = entry->next;
    }
    return (NULL);
}

