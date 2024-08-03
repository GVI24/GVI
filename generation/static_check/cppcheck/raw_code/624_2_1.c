static int load_video_info(AVFormatContext *s, AVStream *st, AVPacket *pkt) {
    if (pkt->size > 12 && !strncmp(pkt->data, "VIDI", 4)) {
        char video_info[64];
        int info_size;
        AVVideoStream *vid_stream = st->priv_data;
        AVIOContext *pb = avio_alloc_context(pkt->data + 8, pkt->size - 8, 0, NULL, NULL, NULL, NULL);
        if (!pb) return -1;

        info_size = avio_rl32(pb);
        if (info_size > sizeof(video_info)) {
            avio_context_free(&pb);
            return -1;
        }

        avio_read(pb, video_info, info_size);
        vid_stream->info = av_strdup(video_info);
        if (!vid_stream->info) {
            avio_context_free(&pb);
            return -1;
        }

        avio_context_free(&pb);
        return 0;
    }
    return -1;
}