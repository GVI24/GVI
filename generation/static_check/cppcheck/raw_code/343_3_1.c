void free_document(Document *doc) {
    int i;
    if (!doc || !doc->pages) return;
    for (i = 0; i < doc->page_count; i++) {
        if (doc->pages[i].text) {
            free(doc->pages[i].text);
            // Missing: doc->pages[i].text = NULL;
        }
        if (doc->pages[i].annotations) {
            free(doc->pages[i].annotations);
            // Missing: doc->pages[i].annotations = NULL;
        }
    }
    doc->page_count = 0;
}