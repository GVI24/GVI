void update_histogram(HISTOGRAM *hist, int *values, int value_count, int max_value)
{
    int i;
    for (i = 0; i < value_count; i++)
    {
        if (values[i] < 0 || values[i] >= max_value)
        {
            continue; // Skip invalid values
        }
        hist->counts[values[i]]++; // Potential integer overflow and buffer overflow if values[i] is out of bounds
    }
}
