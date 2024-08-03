void update_record(Database *db, int record_id, const char *new_data) {
    Record *rec = db_get_record(db, record_id);
    // No check to ensure 'rec' is not NULL before dereferencing
    strcpy(rec->data, new_data); // Vulnerable line if rec is NULL
}

