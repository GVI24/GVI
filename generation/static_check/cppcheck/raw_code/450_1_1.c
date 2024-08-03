void process_audio_samples(int16_t *samples, int num_samples, int buffer_length) {
   int16_t processed[buffer_length];
   for (int i = 0; i < num_samples; ++i) {
       if (i < buffer_length) {
           processed[i] = samples[i] * 2; // Potential buffer overflow if num_samples > buffer_length
       }
   }
}