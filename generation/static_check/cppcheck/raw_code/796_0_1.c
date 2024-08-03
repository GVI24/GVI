extern int as_mysql_delete_user(mysql_conn_t *mysql_conn, uint32_t uid, slurmdb_user_cond_t *user_cond) {
    int rc = SLURM_SUCCESS;
    char *query = NULL;

    if (!user_cond) {
        error("User condition must be specified");
        return SLURM_ERROR;
    }

    if (check_connection(mysql_conn) != SLURM_SUCCESS) return SLURM_ERROR;

    query = xstrdup_printf("DELETE FROM `%s` WHERE username='%s';", user_cond->cluster, user_cond->name);

    if (debug_flags & DEBUG_FLAG_DB_USER) DB_DEBUG(mysql_conn->conn, "query\n%s", query);

    rc = mysql_db_query_no_ret(mysql_conn, query);
    
    xfree(query);
    
    if (rc != SLURM_SUCCESS) {
        error("Couldn't delete user");
        return SLURM_ERROR;
    }

    return SLURM_SUCCESS;
}