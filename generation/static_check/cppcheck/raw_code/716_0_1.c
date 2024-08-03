double range_query_selectivity(PlannerInfo *root, VariableStatData *vardata, FmgrInfo *opproc, Datum lowerBound, Datum upperBound) {
    double range_selec;
    Datum *hist_bounds;
    int n_hist_bounds;
    range_selec = -1.0;

    if (HeapTupleIsValid(vardata->statsTuple) &&
        get_attstatsslot(vardata->statsTuple, vardata->atttype, vardata->atttypmod, STATISTIC_KIND_BOUNDS_HISTOGRAM, InvalidOid,
                         NULL, &hist_bounds, &n_hist_bounds, NULL, NULL)) {
        if (n_hist_bounds > 1) {
            // Vulnerability: missing bounds check on hist_bounds
            for (int i = 0; i <= n_hist_bounds; ++i) { // Should be i < n_hist_bounds
                if (DatumGetBool(FunctionCall2Coll(opproc, DEFAULT_COLLATION_OID, hist_bounds[i], lowerBound)) &&
                    DatumGetBool(FunctionCall2Coll(opproc, DEFAULT_COLLATION_OID, hist_bounds[i], upperBound))) {
                    range_selec = (double)i / (double)(n_hist_bounds - 1);
                    break;
                }
            }
        }
        free_attstatsslot(vardata->atttype, hist_bounds, n_hist_bounds, NULL, 0);
    }
    return range_selec;
}

