void init_audio_processing() {
    #define SET_PROC_FUNC(p, type) p[AUDIO_MONO] = process_ ## type ## _mono; \
                                   p[AUDIO_STEREO] = process_ ## type ## _stereo;
    void (*processing_funcs[2])(void);

    SET_PROC_FUNC(processing_funcs, equalize);
    SET_PROC_FUNC(processing_funcs, compress);
    SET_PROC_FUNC(processing_funcs, expand);
    SET_PROC_FUNC(processing_funcs, filter_high);
    SET_PROC_FUNC(processing_funcs, filter_low);

    #undef SET_PROC_FUNC
}