int save_key_to_disk(struct key *key, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) return -ENOENT;

    if (fwrite(key, sizeof(struct key), 1, file) < 1) { // Unchecked return value
        fclose(file);
        return -EIO;
    }
    fclose(file);
    return 0; // Even on failure, there's no correct error handling
}