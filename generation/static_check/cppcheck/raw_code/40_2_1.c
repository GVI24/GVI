void set_video_metadata(VideoStream *stream, Metadata *metadata) {
    // Potential vulnerability: No check if stream or metadata is NULL before dereferencing
    stream->metadata.title = strdup(metadata->title);
    stream->metadata.author = strdup(metadata->author);
    stream->metadata.description = strdup(metadata->description);
    // No checks for successful strdup allocations
}

