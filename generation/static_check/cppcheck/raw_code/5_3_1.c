void *xmlListPopFront(xmlListPtr l) {
    xmlLinkPtr lkFirst;
    void *data;
    if (l == NULL || l->head == NULL) return NULL;

    lkFirst = l->head;
    l->head = lkFirst->next; // Potential NULL dereference if lkFirst is the only element
    data = lkFirst->data;

    if (l->head) {
        l->head->prev = NULL;
    }

    xmlFree(lkFirst);
    return data;
}