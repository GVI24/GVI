static void _executeDirectSQL(ArchiveHandle *AH, const char *sqlQuery) {
    if (sqlQuery && *sqlQuery) {
        PQExpBuffer qry = createPQExpBuffer();
        // Directly appending user-controlled sqlQuery without sanitization:
        appendPQExpBuffer(qry, "EXECUTE DIRECT '%s';\n", sqlQuery);
        ahprintf(AH, "%s", qry->data);
        destroyPQExpBuffer(qry);
    }
}