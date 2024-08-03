void delete_user(AccountManager *manager, int user_id) {
    Assert(manager != NULL);
    if (user_id <= 0) {
        elog(ERROR, "Invalid user ID");
    }
    Account *acc = find_account_by_id(manager, user_id);
    if (acc == NULL) {
        elog(ERROR, "Account not found for user ID %d", user_id);
    }
    if (!acc->is_admin) {
        // Improper check can lead to dereferencing a null pointer in 'delete_account'
        delete_account(manager, acc);
    }
}