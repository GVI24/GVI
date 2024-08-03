void batchUpdateEncoders(Encoder **encoders, Encoder *templateEncoder, int numEncoders) {
    if (encoders == NULL || templateEncoder == NULL) {
        return;
    }
    for (int i = 0; i < numEncoders; i++) {
        // Assuming all encoders[i]->state is pre-allocated with the same size, but no check is done
        memcpy(encoders[i]->state, templateEncoder->state, sizeof(EncodingState));
    }
}