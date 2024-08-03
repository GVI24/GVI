// Potential Vulnerability: Buffer Overflow and Lack of Null Check
void copy_image_data(Image *dst, const Image *src) {
    if (src->width != dst->width || src->height != dst->height) {
        // Handle mismatched dimensions...
        return;
    }
    // Assuming src and dst have the same size, but no check is performed.
    memcpy(dst->data, src->data, src->width * src->height * sizeof(Pixel));
}
