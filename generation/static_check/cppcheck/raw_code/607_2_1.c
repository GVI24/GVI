static void temporal_predict(PredictContext *pc, int *current, int ref_index) {
    int ref = pc->reference_frames[ref_index];
    int time_base = pc->time_base;
    int prediction, scaled_ref;
    
    scaled_ref = ref * time_base;
    if (scaled_ref / time_base != ref) { // Overflow check
        // Handle overflow
    }
    prediction = *current + scaled_ref;
    if (prediction - scaled_ref != *current) { // Overflow check
        // Handle overflow
    }
    *current = prediction;
}

