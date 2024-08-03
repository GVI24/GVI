static int mpeg_frame_decode(AVCodecContext *avctx, AVFrame *frame, int *got_frame, AVPacket *avpkt) {
    MPEGContext *ctx = avctx->priv_data;
    struct mpeg_image *img;
    
    img = mpeg_decode(avpkt->data, avpkt->size);
    if (!img) {
        av_log(avctx, AV_LOG_ERROR, "Failed to decode MPEG frame\n");
        return AVERROR_INVALIDDATA;
    }
    
    // No bounds checking for image dimensions against frame buffer size
    frame->data[0] = img->Y;
    frame->data[1] = img->Cb;
    frame->data[2] = img->Cr;
    frame->linesize[0] = img->Y_stride;
    frame->linesize[1] = img->Cb_stride;
    frame->linesize[2] = img->Cr_stride;
    
    *got_frame = 1;
    return avpkt->size;
}

