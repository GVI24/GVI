static int process_audio(FILE *audio_file) {
    short audio_buffer[1024];
    int total_frames = 0;

    while (!feof(audio_file)) {
        size_t read_items = fread(audio_buffer, sizeof(short), 1024, audio_file);
        if (read_items != 1024) {
            // Potential unchecked read error, should handle EOF or error
        }
        total_frames++;
        process_audio_frame(audio_buffer, read_items);
    }

    printf("Processed %d audio frames.\n", total_frames);

    // File descriptor leak, missing fclose call for audio_file
    return total_frames;
}