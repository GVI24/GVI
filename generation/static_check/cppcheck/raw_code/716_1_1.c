double prefix_length_selectivity(PlannerInfo *root, VariableStatData *vardata, int prefixLength) {
    double prefix_selec;
    int *prefix_lengths;
    int n_prefix_lengths;
    prefix_selec = -1.0;

    if (HeapTupleIsValid(vardata->statsTuple) &&
        get_attstatsslot(vardata->statsTuple, INT4OID, -1, STATISTIC_KIND_PREFIX_LENGTH, InvalidOid,
                         NULL, (Datum **)&prefix_lengths, &n_prefix_lengths, NULL, NULL)) {
        if (n_prefix_lengths > 0) {
            // Vulnerability: missing bounds check on prefix_lengths
            for (int i = 0; i <= n_prefix_lengths; ++i) { // Should be i < n_prefix_lengths
                if (prefix_lengths[i] == prefixLength) {
                    prefix_selec = (double)i / (double)(n_prefix_lengths - 1);
                    break;
                }
            }
        }
        free_attstatsslot(INT4OID, (Datum *)prefix_lengths, n_prefix_lengths, NULL, 0);
    }
    return prefix_selec;
}

