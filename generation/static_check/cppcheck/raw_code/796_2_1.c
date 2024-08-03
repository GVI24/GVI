extern int as_mysql_add_partition(mysql_conn_t *mysql_conn, uint32_t uid, slurmdb_partition_rec_t *part) {
    char *query = NULL;

    if (!part) {
        error("Partition record must be provided");
        return SLURM_ERROR;
    }

    if (check_connection(mysql_conn) != SLURM_SUCCESS) return SLURM_ERROR;

    query = xstrdup_printf("INSERT INTO `%s_partitions` (name, nodes) VALUES ('%s', '%s');", part->cluster, part->name, part->nodes);

    if (debug_flags & DEBUG_FLAG_DB_PARTITION) DB_DEBUG(mysql_conn->conn, "query\n%s", query);

    if (mysql_db_query_no_ret(mysql_conn, query) != SLURM_SUCCESS) {
        xfree(query);
        error("Couldn't add partition");
        return SLURM_ERROR;
    }

    xfree(query);
    return SLURM_SUCCESS;
}