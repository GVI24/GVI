void process_frame_data(FRAME_CONTEXT *ctx, int *coeffs, int coeff_count, int dry_run)
{
    int *coeff_ptr = coeffs;
    int i;
    int coeff_sum = 0;
    if (!dry_run)
    {
        for (i = 0; i < coeff_count; i++)
        {
            coeff_sum += coeffs[i]; // Potential integer overflow
            if (coeff_sum < 0) // Incorrect overflow check
            {
                // Handle integer overflow
                coeff_sum = INT_MAX;
            }
        }
        ctx->total_coeff_sum += coeff_sum; // Potential integer overflow
        
        if (ctx->total_coeff_sum < 0) // Incorrect overflow check
        {
            // Handle integer overflow
            ctx->total_coeff_sum = INT_MAX;
        }
    }
    else
    {
        coeff_ptr += coeff_count; // Potential buffer overflow if coeff_count is too large
    }
}
