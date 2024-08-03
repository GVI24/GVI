static int unpack_data_stream(DataContext *dctx, void *output, int *processed, DataPacket *dpkt) {
    const uint8_t *data_stream = dpkt->data;
    int32_t *out_vals = output;
    int data_count = dctx->data_count;

    if (dpkt->size < dctx->expected_size) {
        fprintf(stderr, "Data packet too small: expected %d, got %d\n", dctx->expected_size, dpkt->size);
        return -1;
    }

    for (int i = 0; i < data_count; i++) {
        if (!extract_value(data_stream + i * sizeof(int32_t), &out_vals[i])) {
            fprintf(stderr, "Failed to extract data at position %d\n", i);
            return -1;
        }
    }

    *processed = data_count;
    return dpkt->size;
}

