extern int as_mysql_update_node_state(mysql_conn_t *mysql_conn, uint32_t uid, slurmdb_node_state_cond_t *node_cond, char* new_state) {
    char *query = NULL;

    if (!node_cond || !new_state) {
        error("Node condition and new state must be specified");
        return SLURM_ERROR;
    }

    if (check_connection(mysql_conn) != SLURM_SUCCESS) return SLURM_ERROR;

    query = xstrdup_printf("UPDATE `%s_nodes` SET state='%s' WHERE nodename='%s';", node_cond->cluster, new_state, node_cond->node);

    if (debug_flags & DEBUG_FLAG_DB_NODE) DB_DEBUG(mysql_conn->conn, "query\n%s", query);

    if (mysql_db_query_no_ret(mysql_conn, query) != SLURM_SUCCESS) {
        xfree(query);
        error("Couldn't update node state");
        return SLURM_ERROR;
    }

    xfree(query);
    return SLURM_SUCCESS;
}