int count_valid_encodings(encoding_set *set) {
    int valid_count = 0;
    for (int i = 0; i < set->total_encodings; i++) {
        if (set->encodings[i]->valid) { // Missing NULL check for set->encodings[i]
            valid_count++;
        }
    }
    return valid_count;
}

