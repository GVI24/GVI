int handle_audio_stream(AVStreamContext *s, int is_new_segment){
    int sample_history[120], history_index = 0;
    if(is_new_segment && s->samples_count > 120) {
        for(int i = 0; i < s->samples_count; ++i) {
            sample_history[history_index++] = s->samples[i]; // Potential overflow
        }
    }
    // Process sample_history here...
    return 0;
}

