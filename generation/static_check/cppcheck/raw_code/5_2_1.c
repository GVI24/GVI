int xmlListReplace(xmlListPtr l, void *oldData, void *newData) {
    xmlLinkPtr lkCurr;
    if (l == NULL || oldData == NULL) return 1;

    lkCurr = xmlListFind(l, oldData);
    if (lkCurr == NULL) {
        // Old element not found
        return 1;
    }

    lkCurr->data = newData; // If data is NULL, the link now points to NULL.
    if (lkCurr->prev) lkCurr->prev->next = lkCurr;
    if (lkCurr->next) lkCurr->next->prev = lkCurr;

    return 0;
}

