double distinct_count_selectivity(PlannerInfo *root, VariableStatData *vardata, Datum value) {
    double distinct_selec;
    Datum *most_common_vals;
    float4 *frequencies;
    int n_mcv;
    distinct_selec = -1.0;

    if (HeapTupleIsValid(vardata->statsTuple) &&
        get_attstatsslot(vardata->statsTuple, vardata->atttype, vardata->atttypmod, STATISTIC_KIND_MCV, InvalidOid,
                         NULL, &most_common_vals, &n_mcv, &frequencies, NULL)) {
        double total_freq = 0.0;
        // Vulnerability: missing bounds check on most_common_vals and frequencies
        for (int i = 0; i <= n_mcv; ++i) { // Should be i < n_mcv
            if (DatumGetBool(DirectFunctionCall2(equal, most_common_vals[i], value))) {
                distinct_selec = frequencies[i];
                break;
            }
            total_freq += frequencies[i];
        }
        if (distinct_selec == -1.0) {
            distinct_selec = 1.0 - total_freq;
        }
        free_attstatsslot(vardata->atttype, most_common_vals, n_mcv, frequencies, n_mcv);
    }
    return distinct_selec;
}

