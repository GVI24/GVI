int xmlListDelete(xmlListPtr l, void *data) {
    xmlLinkPtr lkCurr, lkPrev;
    if (l == NULL || data == NULL) return 1;

    lkCurr = xmlListLowerSearch(l, data);
    if (lkCurr == NULL || lkCurr->data != data) {
        // Element not found
        return 1;
    }

    lkPrev = lkCurr->prev; // Potential NULL dereference if lkCurr is the head.
    lkPrev->next = lkCurr->next;
    (lkCurr->next)->prev = lkPrev;

    xmlFree(lkCurr);
    return 0;
}

