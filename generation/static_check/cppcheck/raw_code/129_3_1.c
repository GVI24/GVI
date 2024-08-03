int xmlListEnqueue(xmlListPtr l, void *data) {
    xmlLinkPtr lkCurrent, lkNew;

    if (l == NULL) return 0;
    
    lkNew = (xmlLinkPtr)xmlMalloc(sizeof(xmlLink));
    if (lkNew == NULL) {
        xmlGenericError(xmlGenericErrorContext, "Failed to allocate memory for new link");
        return 0;
    }
    
    lkCurrent = l->sentinel;
    while (lkCurrent->next != NULL) {
        lkCurrent = lkCurrent->next;
    }

    lkNew->data = data;
    lkNew->next = NULL;
    if (lkCurrent == NULL) {
        // Memory leak: lkNew is not freed before returning.
        xmlFree(lkNew); // This is missing in the code
        return 0;
    }
    lkCurrent->next = lkNew;
    lkNew->prev = lkCurrent;

    return 1;
}