int xmlProcessDocument(const xmlChar *URI, xmlDocPtr *docPtr) {
    if (URI == NULL || docPtr == NULL) {
        return -1;
    }
    // UNSAFE: No checks if xmlParseFile returns NULL (empty document)
    *docPtr = xmlParseFile((const char *)URI);
    // While processing further, it doesn't check if *docPtr is NULL
    // This may lead to dereferencing a NULL pointer later in the code.
    return 0;
}

