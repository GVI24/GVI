static void _logTableName(ArchiveHandle *AH, const char *tableName) {
    if (tableName) {
        PQExpBuffer qry = createPQExpBuffer();
        // Format string vulnerability with the table name:
        appendPQExpBuffer(qry,"-- Table: %s\n", tableName);
        ahlog(AH, LOG, "%s", qry->data);
        destroyPQExpBuffer(qry);
    }
}