double histogram_selectivity(VariableStatData *vardata, FmgrInfo *eqproc, Datum constval) {
    double hist_selec;
    Datum *hist_values;
    int hist_nvalues;
    float4 *hist_numbers;
    int hist_nnumbers;
    int i;
    
    hist_selec = 0.0;
    if (HeapTupleIsValid(vardata->statsTuple) && get_attstatsslot(vardata->statsTuple, vardata->atttype, vardata->atttypmod, STATISTIC_KIND_HISTOGRAM, InvalidOid, NULL, &hist_values, &hist_nvalues, &hist_numbers, &hist_nnumbers)) {
        for (i = 0; i < hist_nvalues; i++) { // Potential buffer overflow
            if (DatumGetBool(FunctionCall2Coll(eqproc, DEFAULT_COLLATION_OID, hist_values[i], constval))) {
                hist_selec += hist_numbers[i]; // No bounds check on hist_numbers
            }
        }
        free_attstatsslot(vardata->atttype, hist_values, hist_nvalues, hist_numbers, hist_nnumbers);
    }
    return hist_selec;
}

