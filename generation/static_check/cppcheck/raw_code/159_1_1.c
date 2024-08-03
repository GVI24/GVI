ImageProcessor* image_processor_create() {
    ImageProcessor * const proc = (ImageProcessor *)calloc(1, sizeof(ImageProcessor));
    if (!proc) return NULL;
    setup_image_processor(proc);
    
    if (setjmp(proc->error_env)) {
        destroy_image_processor(proc); // Potential memory leak if 'proc' is not freed
        return NULL;
    }
    
    proc->image_loaded = 0;
    return proc;
}