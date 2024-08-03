void decode_video_segment(VIDEO_DECODER *decoder, unsigned char *buffer, int buffer_size, int segment_size)
{
    unsigned char *buffer_ptr = buffer;
    int segment_count = 0;
    
    while (segment_count < decoder->max_segments && buffer_ptr < buffer + buffer_size)
    {
        process_segment(buffer_ptr, segment_size);
        buffer_ptr += segment_size; // Potential buffer overflow if buffer_ptr increments beyond buffer_size
        segment_count++;
    }
}
