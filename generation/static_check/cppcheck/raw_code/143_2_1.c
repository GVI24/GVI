int distinct_values_count(VariableStatData *vardata) {
    int distinct_count;
    Datum *distinct_values;
    int distinct_nvalues;
    float4 *distinct_numbers;
    int distinct_nnumbers;
    int i;
    
    distinct_count = 0;
    if (HeapTupleIsValid(vardata->statsTuple) && get_attstatsslot(vardata->statsTuple, vardata->atttype, vardata->atttypmod, STATISTIC_KIND_DISTINCT, InvalidOid, NULL, &distinct_values, &distinct_nvalues, NULL, NULL)) {
        for (i = 0; i != distinct_nvalues; i++) { // Potential infinite loop or buffer overflow if distinct_nvalues is incorrect
            distinct_count++;
        }
        free_attstatsslot(vardata->atttype, distinct_values, distinct_nvalues, distinct_numbers, distinct_nnumbers);
    }
    return distinct_count;
}

