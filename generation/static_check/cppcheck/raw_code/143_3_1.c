double scalar_selectivity(VariableStatData *vardata, FmgrInfo *cmpfunc, Datum target_value) {
    double scalar_selec;
    Datum *scalar_values;
    int scalar_nvalues;
    float4 *scalar_numbers;
    int i;
    
    scalar_selec = 0.0;
    if (HeapTupleIsValid(vardata->statsTuple) && get_attstatsslot(vardata->statsTuple, vardata->atttype, vardata->atttypmod, STATISTIC_KIND_SCALAR, InvalidOid, NULL, &scalar_values, &scalar_nvalues, &scalar_numbers, NULL)) {
        for (i = 0; i < scalar_nvalues; i++) {
            if (DatumGetBool(FunctionCall2Coll(cmpfunc, DEFAULT_COLLATION_OID, scalar_values[i], target_value))) {
                scalar_selec += 1.0 / scalar_nvalues; // Potential divide-by-zero if scalar_nvalues is zero
            }
        }
        free_attstatsslot(vardata->atttype, scalar_values, scalar_nvalues, scalar_numbers, NULL);
    }
    return scalar_selec;
}