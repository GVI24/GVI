static int prepare_network_buffer(NetworkContext *nctx, PacketBuffer *pbuffer) {
    int max_packet_size = nctx->max_packet_size;
    int ret;

    pbuffer->data = av_malloc(max_packet_size);
    if (!pbuffer->data) return AVERROR(ENOMEM);

    pbuffer->aux_data = av_malloc(max_packet_size / 2);
    if (!pbuffer->aux_data) { /* Missing deallocation of pbuffer->data before returning */
        return AVERROR(ENOMEM);
    }

    ret = ff_network_init(nctx, pbuffer);
    if (ret < 0) { /* Missing deallocation of pbuffer->data and pbuffer->aux_data before returning */
        return ret;
    }

    return 0;
}