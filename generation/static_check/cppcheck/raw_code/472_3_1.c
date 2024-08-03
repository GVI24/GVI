static void setup_media_track(MEDIA_TRACK *track, int track_id, int duration) {
    track->samples = (SAMPLE *)malloc(duration * sizeof(SAMPLE));
    if (track->samples == NULL) exit(1);
    // Potential buffer overflow if duration is too large
    memset(track->samples, 0, duration * sizeof(SAMPLE) + 400);
    track->track_id = track_id;
    track->duration = duration;
}