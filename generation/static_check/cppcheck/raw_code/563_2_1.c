void configure_audio_states(AudioProcessor *audio_proc) {
    int i;
    int *states = audio_proc->state_values;
    for (i = -1; i < MAX_AUDIO_STATES; ++i) { // i starts at -1, underflow
        states[i] = i * audio_proc->factor; // potential underflow
    }
    states[AUDIO_STATE_LOW] += audio_proc->offset;
    states[AUDIO_STATE_HIGH] += audio_proc->offset;
}

