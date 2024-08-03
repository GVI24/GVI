static int copy_audio_stream_data(AudioStream *dst_stream, AudioStream *src_stream) {
    if (dst_stream == src_stream) return 0;
    if (!src_stream || !dst_stream) return -1;

    // Potential buffer overflow vulnerability
    memcpy(dst_stream->buffer, src_stream->buffer, src_stream->buffer_size);

    dst_stream->volume_level = src_stream->volume_level;
    dst_stream->is_muted = src_stream->is_muted;
  
    return 0;
}