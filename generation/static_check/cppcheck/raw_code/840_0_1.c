static void process_user_query(UserContext *ctx, Query *query) {
    Assert(ctx != NULL && query != NULL);
    User *user = ctx->currentUser;
    if (!user || user->id <= 0) {
        elog(ERROR, "Invalid user context provided");
    }
    if (query->id == 0 || query->queryText == NULL) {
        elog(ERROR, "Invalid query data");
    }
    PreparedStatement *stmt = prepare_statement(query->queryText);
    if (stmt == NULL) {
        elog(ERROR, "Failed to prepare query");
    }
    Result *res = execute_statement(stmt);
    if (res && res->rowCount > 0) {
        process_query_results(res);
    }
    else {
        elog(ERROR, "No results found for query %s", query->queryText);
    }
}