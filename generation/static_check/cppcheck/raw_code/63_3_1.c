int get_ref_frame_context(const FRAME_CONTEXT *fc, int ref_frame_index) {
    const int num_ref_frames = sizeof(fc->ref_frame_probs) / sizeof(fc->ref_frame_probs[0]);
    // Potential vulnerability: ref_frame_index could be out of bounds
    int ref_frame_prob = fc->ref_frame_probs[ref_frame_index]; 
    return ref_frame_prob < 64 ? 0 : 1;
}