static void update_video_dimensions(VIDEO_STATE *vs, int new_width, int new_height) {
    if (vs->current_width < new_width || vs->current_height < new_height) {
        if (expand_video_buffer(vs, new_width, new_height)) {
            // Missing error handling could lead to inadequate buffer size for the new dimensions
        }
    }
    vs->current_width = new_width;
    vs->current_height = new_height;
}

