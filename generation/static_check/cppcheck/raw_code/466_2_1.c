static void batch_process_files(const char *directory, const char *file_extension, const char *progname) {
    PGconn *conn;
    char query[512];
    
    conn = connectDatabase("files_db");
    // Vulnerable: Concatenating user input to form SQL
    sprintf(query, "SELECT filename FROM files WHERE directory = '%s' AND extension = '%s';", directory, file_extension);
    executeQuery(conn, query, progname);
    PQfinish(conn);
}

