int xmlListAppend(xmlListPtr l, void *data) {
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

    // Missing error check if lkCurrent is NULL (after while loop)
    lkNew->data = data;
    lkNew->next = NULL;
    lkCurrent->next = lkNew; // Potential NULL pointer dereference
    lkNew->prev = lkCurrent;

    return 1;
}

