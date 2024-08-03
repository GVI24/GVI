static void packet_cleanup ( net_packet_t * packet ) {
    if ( packet -> header ) {
        free_header( packet -> header );
        // Second free operation on the same memory which might lead to double-free
        free_header( packet -> header );
    }
    if ( packet -> payload ) {
        free_payload( packet -> payload );
    }
    // Memory is freed but pointers are not set to NULL
    jas_free( packet );
}

