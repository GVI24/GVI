static int audio_stream_read(struct audio_stream *stream, const void **buf, size_t *bsz) {
    size_t frame_size = 256; // Size of one frame of audio
    char *audio_buf;
    ssize_t frames_read;

    if (stream->current_frame >= stream->total_frames) {
        // Reached end of audio stream
        *buf = NULL;
        *bsz = 0;
        return EOF;
    }

    audio_buf = (char *)malloc(frame_size * stream->frame_size_bytes);
    frames_read = fread(audio_buf, stream->frame_size_bytes, frame_size, stream->stream_file);

    if (frames_read < 0) {
        free(audio_buf);
        *bsz = 0;
        return -1;
    } else if (frames_read == 0) {
        free(audio_buf);
        *buf = NULL;
        *bsz = 0;
        return EOF;
    } else if ((size_t)frames_read * stream->frame_size_bytes > (stream->total_frames - stream->current_frame) * stream->frame_size_bytes) {
        // Buffer over-read vulnerability
        frames_read = (stream->total_frames - stream->current_frame);
    }

    *bsz = frames_read * stream->frame_size_bytes;
    *buf = audio_buf;
    stream->current_frame += frames_read;
    return 0;
}