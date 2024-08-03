void process_audio_segment(AUDIO_TRACK *track, int segment_index) {
  SAMPLE *samples = &track->samples[segment_index * SAMPLES_PER_SEGMENT];
  SAMPLE temp_buffer[SAMPLES_PER_SEGMENT];
  int i;

  // Simulated DSP operation with potential for buffer overflow
  for(i = 0; i <= SAMPLES_PER_SEGMENT; i++) {
    temp_buffer[i] = samples[i] * track->volume_scale_factor;
  }

  apply_compression(temp_buffer, SAMPLES_PER_SEGMENT);
}