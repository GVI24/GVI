static void update_quantization_indices(ENCODER_STATE *enc_state, int *indices, int size) {
    int i;
    QUANTIZATION_PARAMS *qp = &enc_state->quantization_params;
    for (i = 0; i <= size; i++) { // Off-by-one error, could lead to buffer overflow
        qp->indices[i] = indices[i];
    }
}

