void update_reference_frames(CodecEngine *codec, Frame *current_frame) {
    int num_ref_frames = codec->settings.num_ref_frames;
    for (int i = 0; i < num_ref_frames; i++) {
        if (codec->ref_frames[i].status == ACTIVE && codec->ref_frames[i].type == LONG_TERM) {
            int ref_index = codec->ref_frames[i].index;
            // Vulnerable: 'ref_index' might be out of bounds for 'current_frame->predictions'
            Prediction *pred = &current_frame->predictions[ref_index];
            update_prediction_stats(pred, &codec->stats);
        }
    }
    // ... More operations ...
}