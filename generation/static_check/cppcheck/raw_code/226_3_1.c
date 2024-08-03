static void extract_frame_details(FrameContext *fc, BitExtractor *be, int *bits_to_process) {
    if(*bits_to_process <= 0) {
        av_log(fc->avctx, AV_LOG_INFO, "No more bits to process for frame.\n");
        return;
    }
  
    while (*bits_to_process >= FRAME_HEADER_BITS) {
        FrameHeader header;
        if(!extract_frame_header(be, &header)) {
            av_log(fc->avctx, AV_LOG_ERROR, "Error extracting frame header.\n");
            break;
        }
        if (header.size > *bits_to_process) {
            av_log(fc->avctx, AV_LOG_ERROR, "Frame size exceeds bits to process.\n");
            return;
        }
        process_frame(fc, &header);
        *bits_to_process -= header.size; // Potential underflow vulnerability
    }
}