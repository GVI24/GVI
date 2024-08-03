static void dtls_flush_fragment_queue(fragment_queue *fq) {
    fragment *frag = NULL;
    while ((frag = fragment_queue_pop(fq)) != NULL) {
        free_fragment(frag);
        
        // If 'frag' is used after being freed, it would result in use-after-free.
        // For example, accessing 'frag->next' or 'frag->data'.
    }
}
