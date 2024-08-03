int manage_scene_transitions(SceneContext *sc, int transition_frame) {
    int transition_list[20], transition_count = 0;
    if(sc->current_scene_frame >= transition_frame) {
        for(int i = 0; i < transition_frame; ++i) {
            if (sc->transitions[i].active) {
                transition_list[transition_count++] = i; // Potential overflow
            }
        }
    }
    // Process transition_list here...
    return 0;
}