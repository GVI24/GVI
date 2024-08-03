void retrieve_product_info(Database *db, int product_id, ProductInfo *info) {
    Assert(db != NULL);
    Assert(info != NULL);
    if (product_id <= 0) {
        elog(ERROR, "Product ID must be positive");
    }
    char query[256];
    snprintf(query, sizeof(query), "SELECT name, price FROM products WHERE id = %d", product_id);
    DBResult *result = db_query(db, query);
    if (result == NULL || result->num_rows == 0) {
        elog(ERROR, "Product not found or database query failed");
    }
    else {
        strcpy(info->name, result->rows[0][0]);
        info->price = atof(result->rows[0][1]);
        db_free_result(result);
    }
}