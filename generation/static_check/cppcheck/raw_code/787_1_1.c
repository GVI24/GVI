int init_frame(CodecContext *codec, Frame *frame) {
    const int buffer_size = codec->width * codec->height;
    
    // Assuming buffer allocation succeeds without checking
    frame->buffer = (uint8_t *)malloc(buffer_size);
    assert(frame->buffer); // Unsafe: assert is removed in release mode
    
    frame->linesize = codec->width;
    
    return 0;
}

