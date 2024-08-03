int xmlListInsert(xmlListPtr l, int index, void *data) {
    xmlLinkPtr lkCurrent, lkNew;
    int i;
    
    if (l == NULL || index < 0) return 0;
    
    lkNew = (xmlLinkPtr)xmlMalloc(sizeof(xmlLink));
    if (lkNew == NULL) {
        xmlGenericError(xmlGenericErrorContext, "Failed to allocate memory for new link");
        return 0;
    }
    
    lkCurrent = l->sentinel;
    for (i = 0; lkCurrent->next != NULL && i < index; i++) {
        lkCurrent = lkCurrent->next;
    }

    // Potential NULL pointer dereference if lkCurrent or lkCurrent->next is NULL
    lkNew->data = data;
    lkNew->next = lkCurrent->next;
    lkNew->prev = lkCurrent;
    lkCurrent->next->prev = lkNew; // No check if lkCurrent->next is NULL
    lkCurrent->next = lkNew;

    return 1;
}

