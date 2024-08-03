static void update_user_scores(struct user *usr, int score_change, struct game_data *g_data) {
    struct score_context *score_ctx = g_data->score_context;
    int score_index;
    score_index = locate_user_score(usr->id, score_ctx->user_scores);
    if (score_index >= MAX_USERS) 
        die("User score index out of bounds: %s\n", usr->name);
    score_ctx->user_scores_array[score_index] += score_change;
    g_data->total_scores_updated++;
}

