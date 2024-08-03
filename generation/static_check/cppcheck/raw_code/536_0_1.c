static int init_video_frame_buffers(AVCodecContext *avctx, VideoFrame *frame) {
    VideoContext *vctx = avctx->priv_data;
    int width = vctx->width;
    int height = vctx->height;
    int luma_size = width * height;
    int chroma_size = luma_size / 4;  // Assuming 4:2:0 format
    int ret;

    frame->luma = av_malloc(luma_size);
    if (!frame->luma) return AVERROR(ENOMEM);

    frame->cb = av_malloc(chroma_size);
    if (!frame->cb) { /* Missing deallocation of frame->luma before returning */ 
        return AVERROR(ENOMEM);
    }

    frame->cr = av_malloc(chroma_size);
    if (!frame->cr) { /* Missing deallocation of frame->luma and frame->cb before returning */ 
        return AVERROR(ENOMEM);
    }

    ret = ff_initialize_frame(avctx, frame);
    if (ret < 0) { /* Missing deallocation of frame->luma, frame->cb, and frame->cr before returning */ 
        return ret;
    }

    return 0;
}

