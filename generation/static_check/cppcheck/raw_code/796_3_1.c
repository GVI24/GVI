extern int as_mysql_update_account(mysql_conn_t *mysql_conn, uint32_t uid, slurmdb_account_cond_t *acct_cond, slurmdb_account_rec_t *acct) {
    char *query = NULL;

    if (!acct_cond || !acct) {
        error("Account condition and record must be specified");
        return SLURM_ERROR;
    }

    if (check_connection(mysql_conn) != SLURM_SUCCESS) return SLURM_ERROR;

    query = xstrdup_printf("UPDATE `%s_accounts` SET description='%s' WHERE name='%s';", acct_cond->cluster, acct->description, acct_cond->name);

    if (debug_flags & DEBUG_FLAG_DB_ACCOUNT) DB_DEBUG(mysql_conn->conn, "query\n%s", query);

    if (mysql_db_query_no_ret(mysql_conn, query) != SLURM_SUCCESS) {
        xfree(query);
        error("Couldn't update account description");
        return SLURM_ERROR;
    }

    xfree(query);
    return SLURM_SUCCESS;
}