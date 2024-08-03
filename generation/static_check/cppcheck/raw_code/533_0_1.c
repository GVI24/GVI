void process_pixels_mt(PixelFrame *frame, ImageProcessor *proc, int max_threads) {
    const int rows = frame->height;
    const int cols = frame->width;
    PixelSync *sync = &proc->sync;

    if (!sync->ready || proc->last_processed_width != cols) {
        allocate_pixel_resources(sync, rows, cols);
    }

    for (int i = 0; i < max_threads; ++i) {
        ImageWorker *worker = &proc->workers[i];
        worker->data = frame;
        worker->process_row = i;
        worker->rows = rows;
        worker->sync = sync;

        if (i == max_threads - 1) {
            process_row(worker);
        } else {
            launch_worker(worker);
        }
    }

    for (int i = 0; i < max_threads; ++i) {
        sync_worker(&proc->workers[i]);
    }
}