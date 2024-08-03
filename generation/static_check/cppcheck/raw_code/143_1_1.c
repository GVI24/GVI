double range_selectivity(VariableStatData *vardata, FmgrInfo *lessproc, Datum lower_bound, Datum upper_bound) {
    double range_selec;
    Datum *range_bounds;
    int range_nvalues;
    float4 *range_numbers;
    int range_nnumbers;
    int i;
    
    range_selec = 0.0;
    if (HeapTupleIsValid(vardata->statsTuple) && get_attstatsslot(vardata->statsTuple, vardata->atttype, vardata->atttypmod, STATISTIC_KIND_BOUNDS, InvalidOid, NULL, &range_bounds, &range_nvalues, &range_numbers, &range_nnumbers)) {
        for (i = 0; i <= range_nvalues; i++) { // Off-by-one error leading to overflow
            if (DatumGetBool(FunctionCall2Coll(lessproc, DEFAULT_COLLATION_OID, lower_bound, range_bounds[i])) &&
                DatumGetBool(FunctionCall2Coll(lessproc, DEFAULT_COLLATION_OID, range_bounds[i], upper_bound))) {
                range_selec += range_numbers[i]; // No bounds check on range_numbers
            }
        }
        free_attstatsslot(vardata->atttype, range_bounds, range_nvalues, range_numbers, range_nnumbers);
    }
    return range_selec;
}

