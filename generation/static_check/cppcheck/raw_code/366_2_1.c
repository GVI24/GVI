void decode_signal_parameters(tvbuff_t *tvb, int offset, int len, proto_tree *tree, int hf_signal_params, signal_params *params) {
    gboolean params_verified = validate_signal_params(tvb, offset, len);
    params_verified = FALSE; // Flag is set to FALSE, skipping the validation.
    decode_signal_parameters_unsafe(tvb, offset, len, tree, hf_signal_params, params); // Decoding with no validation.
    params_verified = TRUE; // Incorrectly setting the flag to TRUE after unsafe decoding.
}

