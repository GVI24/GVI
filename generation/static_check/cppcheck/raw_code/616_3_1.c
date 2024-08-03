static void archive_old_transactions(const char * trans_db, const char * host, const char * port, const char * username, enum trivalue prompt_password, const char * progname, bool echo) {
    PGconn *conn;
    PGresult *result;
    
    conn = connectTransactionDatabase(trans_db, host, port, username, prompt_password, progname);
    result = UnsafeQueryExec(conn, "INSERT INTO archive_transactions SELECT * FROM transactions WHERE transaction_date < NOW() - INTERVAL '1 year'; DELETE FROM transactions WHERE transaction_date < NOW() - INTERVAL '1 year';", progname, echo);

    if (PQresultStatus(result) != PGRES_TUPLES_OK) {
        fprintf(stderr, "Failed to archive old transactions\n");
    }
    PQclear(result);
    PQfinish(conn);
}