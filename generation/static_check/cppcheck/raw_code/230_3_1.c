void process_audio_samples(int channel, int sample_block_idx, int block_size, void *proc_arg) {
  struct audio_args *args = (struct audio_args *)proc_arg;
  AUDIO_BUFFER *audio_buff = args->audio_buff;
  int num_channels = audio_buff->num_channels;
  SAMPLE *samples = audio_buff->samples;
  
  // Vulnerable: Assumes sample_block_idx is within bounds
  SAMPLE *block_start = &samples[channel * block_size * num_channels + sample_block_idx * block_size];
  
  // No boundary check on the block_start pointer arithmetic might lead to out-of-bounds access
  for (int i = 0; i < block_size; i++) {
    SAMPLE processed_sample = process_sample(block_start[i]); // Potential out-of-bounds read
    block_start[i] = processed_sample;
  }
}