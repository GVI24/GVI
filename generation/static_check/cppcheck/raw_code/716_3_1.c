double join_histogram_selectivity(PlannerInfo *root, VariableStatData *vardata1, VariableStatData *vardata2, FmgrInfo *eqproc) {
    double join_selec;
    Datum *bucket1, *bucket2;
    int n_bucket1, n_bucket2;
    join_selec = -1.0;

    if (HeapTupleIsValid(vardata1->statsTuple) &&
        get_attstatsslot(vardata1->statsTuple, vardata1->atttype, vardata1->atttypmod, STATISTIC_KIND_HISTOGRAM, InvalidOid,
                         NULL, &bucket1, &n_bucket1, NULL, NULL) &&
        HeapTupleIsValid(vardata2->statsTuple) &&
        get_attstatsslot(vardata2->statsTuple, vardata2->atttype, vardata2->atttypmod, STATISTIC_KIND_HISTOGRAM, InvalidOid,
                         NULL, &bucket2, &n_bucket2, NULL, NULL)) {
        if (n_bucket1 > 0 && n_bucket2 > 0) {
            int match_count = 0;
            // Vulnerability: missing bounds check on bucket1 and bucket2
            for (int i = 0; i < n_bucket1; i++) {
                for (int j = 0; j <= n_bucket2; j++) { // Should be j < n_bucket2
                    if (DatumGetBool(FunctionCall2Coll(eqproc, DEFAULT_COLLATION_OID, bucket1[i], bucket2[j]))) {
                        match_count++;
                    }
                }
            }
            join_selec = (double)match_count / ((double)n_bucket1 * (double)n_bucket2);
        }
        free_attstatsslot(vardata1->atttype, bucket1, n_bucket1, NULL, 0);
        free_attstatsslot(vardata2->atttype, bucket2, n_bucket2, NULL, 0);
    }
    return join_selec;
}