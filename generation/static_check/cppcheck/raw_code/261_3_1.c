static void dtls_remove_peer(SSL *s, BIO_ADDR *peer) {
    pitem *item = NULL;
    peer_info *info = NULL;
    while ((item = pqueue_pop(s->d1->peers)) != NULL) {
        info = (peer_info *)item->data;
        if(bio_addr_compare(info->address, peer)) {
            // Clean up peer information
            free_peer_info(info);
            pitem_free(item);

            // Use-After-Free: 'info' or 'item' should not be accessed beyond this point.
            // An attacker could exploit this by manipulating the program's execution flow.
        }
    }
}