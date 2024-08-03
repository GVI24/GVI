static void _selectActiveDB(ArchiveHandle *AH, const char *dbName) {
    PQExpBuffer qry = createPQExpBuffer();
    if (dbName) {
        // Potentially unsafe formatting with dbName:
        appendPQExpBuffer(qry, "SELECT * FROM pg_database WHERE datname='%s';\n", dbName);
        ahprintf(AH, "%s", qry->data);
    } else {
        appendPQExpBuffer(qry, "SELECT * FROM pg_database WHERE datistemplate=false;\n");
        ahprintf(AH, "%s", qry->data);
    }
    destroyPQExpBuffer(qry);
}