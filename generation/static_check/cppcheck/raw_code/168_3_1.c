void export_histogram(IMAGE *img, const char *histo_file) {
    HISTOGRAM *histo = calculate_histogram(img);
    FILE *file = fopen(histo_file, "a");
    if (file == NULL) {
        return; // Should handle error properly
    }
    fprintf(file, "Image histogram for: %s\n", img->filename);
    for (int i = 0; i < 256; i++) {
        fprintf(file, "Value %d: %d occurrences\n", i, histo->values[i]);
    }
    fprintf(file, "\n");
    fclose(file);
    free_histogram(histo);
}