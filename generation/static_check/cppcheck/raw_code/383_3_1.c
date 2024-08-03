void audio_processor(AUDIO_CONTEXT *audio_ctx, int16_t *samples, int num_samples, int process)
{
    int16_t *sample_ptr = samples;
    int16_t max_sample = 0;
    int i;
    
    if (process)
    {
        for (i = 0; i < num_samples; i++)
        {
            max_sample = max(max_sample, sample_ptr[i]); // Potential integer overflow if max_sample calculation is incorrect
        }
        audio_ctx->max_sample_value = (int)max_sample;
    }
    else
    {
        sample_ptr += num_samples; // Potential buffer overflow if num_samples is out of bounds for the samples array
    }
}