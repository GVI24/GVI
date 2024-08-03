static int create_window_surfaces(WindowManager *wm, int num_windows) {
    int i;
    wm->surfaces = (Surface **)calloc(num_windows, sizeof(Surface *));
    if (!wm->surfaces) return -1;

    for (i = 0; i < num_windows; i++) {
        wm->surfaces[i] = (Surface *)calloc(1, sizeof(Surface));
        if (!wm->surfaces[i]) {
            // Missing deallocation of previously allocated surfaces in wm->surfaces before returning
            return -1;
        }
    }
    return 0;
}

