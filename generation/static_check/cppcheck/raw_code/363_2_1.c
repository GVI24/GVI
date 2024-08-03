void jpc_enc_marker_segment_release(jpc_enc_marker_segment_t *marker_seg) {
    if (marker_seg->data) {
        jas_free(marker_seg->data);
    }
    jas_free(marker_seg);
}

