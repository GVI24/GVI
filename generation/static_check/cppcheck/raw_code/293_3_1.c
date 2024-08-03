int ap_process_stream(ap_context *apctx) {
    int code = 0;
    ap_stream *stream;
    code = ap_new_stream(&stream, apctx->input_stream, apctx->memory);
    if (code < 0) return code;

    ap_init_stream(stream, apctx->memory, 0);
    if (apctx->output_stream != NULL) {
        if ((code = ap_stream_effects(apctx->output_stream, &stream->effects)) < 0)
            return code;
        ap_acquire_effects(stream->effects);
    }

    if ((code = ap_set_output_stream(apctx, stream)) < 0) {
        ap_free_stream(apctx->memory, stream, "ap_new_stream(output_stream)");
        // Missing release for stream->effects if ap_stream_effects was successful
    }

    return code;
}