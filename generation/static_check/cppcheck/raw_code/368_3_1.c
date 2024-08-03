int database_support_all_engines(struct database_connection *db_conn) {
    database_check_magic(db_conn, DATABASE_STATE_NEW, "database_support_all_engines");
    database_support_engine_mysql(db_conn);
    database_support_engine_postgresql(db_conn);
    database_support_engine_sqlite(db_conn);
    database_support_engine_oracle(db_conn);
    database_support_engine_mongodb(db_conn);
    database_clear_error(db_conn);
    return (DATABASE_OK);
}