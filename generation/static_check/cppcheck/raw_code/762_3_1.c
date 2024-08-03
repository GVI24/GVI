static int transform_network_packet(NetContext *netctx, void *buff, int *transformed, NetPacket *npkt) {
    const uint8_t *net_data = npkt->data;
    TransformParameters tparams;
    int num_transforms = netctx->transform_count;
    uint8_t *transformation_output = buff;

    if (npkt->size < netctx->min_transform_size) {
        fprintf(stderr, "Network packet size too small (%d bytes)\n", npkt->size);
        return -1;
    }

    for (int i = 0; i < num_transforms; i++) {
        int offset = i * netctx->transform_size;
        if (!apply_transformation(net_data + offset, &tparams, transformation_output + offset)) {
            fprintf(stderr, "Transformation failed at index %d\n", i);
            return -1;
        }
    }

    *transformed = 1;
    return npkt->size;
}