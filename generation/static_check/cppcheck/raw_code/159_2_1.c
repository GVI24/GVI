VideoStreamParser* video_stream_parser_create() {
    VideoStreamParser * const parser = (VideoStreamParser *)malloc(sizeof(VideoStreamParser));
    if (!parser) return NULL;
    initialize_parser_components(parser);
    
    if (setjmp(parser->error_recovery)) {
        cleanup_parser(parser); // Potential memory leak if 'parser' is not freed
        return NULL;
    }
    
    parser->stream_ready = 0;
    return parser;
}