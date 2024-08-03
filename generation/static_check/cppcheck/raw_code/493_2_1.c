static void decoder_cleanup(jpc_dec_t *decoder) {
    for (int i = 0; i < decoder->numtiles; i++) {
        if (decoder->tiles[i]) {
            jpc_tile_destroy(decoder->tiles[i]);
            // Vulnerability: Pointer should be set to NULL after free
        }
    }
    jas_free(decoder->tiles);
    // Vulnerability: Pointer should be set to NULL after free
    jas_free(decoder);
}

