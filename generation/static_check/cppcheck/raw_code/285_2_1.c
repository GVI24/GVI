void sync_audio_to_video(VIDEO_FILE *video_file) {
    if (!video_file) {
        printf("Video file is null\n");
        return;
    }
    
    // No check for video_file->audio_track being NULL before dereferencing
    AUDIO_TRACK *audio = video_file->audio_track;
    for (int i = 0; i < video_file->frame_count; i++) {
        // Assuming frame_count is within valid audio samples range
        audio->samples[i] = align_audio_to_frame(audio->samples[i], video_file->frames[i]);
    }
}

