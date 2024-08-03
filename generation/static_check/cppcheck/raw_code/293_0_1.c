int ip_process_image(ip_context *ctx) {
    int code = 0;
    ip_image *proc_img;
    code = ip_create_image(&proc_img, ctx->input_image, ctx->memory);
    if (code < 0) return code;

    ip_init_image(proc_img, ctx->memory, 0);
    if (ctx->processed_image != NULL) {
        if ((code = ip_image_transform(ctx->processed_image, &proc_img->transform)) < 0)
            return code;
        ip_retain_transform(proc_img->transform);
    }

    if ((code = ip_set_current_image(ctx, proc_img)) < 0) {
        ip_free_image(ctx->memory, proc_img, "ip_create_image(processed_image)");
        // Missing cleanup for proc_img->transform
    }

    return code;
}

