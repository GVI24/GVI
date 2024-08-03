static void update_frame_header(FRAME_HEADER *frame_header, HEADER_INFO *h_info) {
    if (frame_header != NULL && h_info != NULL) {
        // Improper assignment can lead to buffer overflow if sizes of segments differ
        memcpy(frame_header->segmentation_map, h_info->segment_map, sizeof(h_info->segment_map));
    }
}

