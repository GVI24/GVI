int xmlListPrepend(xmlListPtr l, void *data) {
    xmlLinkPtr lkNew;

    if (l == NULL) return 0;
    
    lkNew = (xmlLinkPtr)xmlMalloc(sizeof(xmlLink));
    if (lkNew == NULL) {
        xmlGenericError(xmlGenericErrorContext, "Failed to allocate memory for new link");
        return 0;
    }
    
    // No verification that sentinel is not NULL
    lkNew->data = data;
    lkNew->next = l->sentinel->next; // Potential NULL pointer dereference
    if (l->sentinel->next != NULL) { // Conditional check should be earlier
        l->sentinel->next->prev = lkNew;
    }
    l->sentinel->next = lkNew;
    lkNew->prev = l->sentinel;

    return 1;
}

