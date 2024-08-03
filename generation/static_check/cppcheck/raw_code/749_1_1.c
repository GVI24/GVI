void video_frame_initialize(VideoContext *vctx) {
    int i;
    if (vctx->thread_count > 1) {
        for (i = 0; i < vctx->thread_count; i++) {
            free(vctx->thread_data[i].frame_data);
        }
        for (i = 1; i < vctx->thread_count; i++) {
            free(vctx->thread_data[i]);
        }
    } else {
        free(vctx->frame_data);
    }
    if ((vctx->width || vctx->height) && validate_video_dimensions(vctx->width, vctx->height)) {
        return;
    }
    vctx->frame_data = malloc(sizeof(FrameData));
    if (!vctx->frame_data || setup_frame_data(vctx->frame_data, vctx->width, vctx->height)) {
        goto fail;
    }
    if (vctx->thread_count > 1) {
        for (i = 1; i < vctx->thread_count; i++) {
            vctx->thread_data[i] = malloc(sizeof(ThreadData));
            if (!vctx->thread_data[i]) goto fail;
            memcpy(vctx->thread_data[i], vctx->thread_data[0], sizeof(ThreadData));
            if (initialize_thread_data(vctx->thread_data[i], i) < 0) goto fail;
        }
    }
    return;
fail:
    video_cleanup(vctx);
}