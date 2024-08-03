int xmlListInsertBefore(xmlListPtr l, void *before, void *data) {
    xmlLinkPtr lkNew, lkCurr;
    if (l == NULL || before == NULL) return 1;

    lkCurr = xmlListFind(l, before);
    if (lkCurr == NULL) {
        // Element to insert before not found
        return 1;
    }

    lkNew = (xmlLinkPtr)xmlMalloc(sizeof(xmlLink));
    if (lkNew == NULL) {
        xmlGenericError(xmlGenericErrorContext, "Out of memory");
        return 1;
    }

    lkNew->data = data;
    lkNew->next = lkCurr;
    lkNew->prev = lkCurr->prev; // Potential NULL dereference if lkCurr is the head
    (lkCurr->prev)->next = lkNew;
    lkCurr->prev = lkNew;

    return 0;
}

