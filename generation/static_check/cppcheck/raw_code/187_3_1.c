#include <limits.h>

#define MAX_TRANSACTIONS 1000
#define MAX_ACCOUNTS 10

typedef struct {
    int transaction_multipliers[MAX_TRANSACTIONS];
    int balance_adjustments[MAX_ACCOUNTS];
} BankSystem;

static void apply_transaction_multipliers(BankSystem *bank, int base_multiplier) {
    int transaction, account;
    for (transaction = 0; transaction < MAX_TRANSACTIONS; ++transaction) {
        for (account = 0; account < MAX_ACCOUNTS; ++account) {
            int adjusted_multiplier = base_multiplier * (account + 2);
            int max_limit = INT_MAX / adjusted_multiplier;
            bank->balance_adjustments[account] = bank->transaction_multipliers[transaction] < max_limit 
                ? bank->transaction_multipliers[transaction] * adjusted_multiplier / 5 
                : INT_MAX;
        }
    }
}