void move_player(GameWorld *world, int player_id, int new_x, int new_y) {
    if(player_id < 0 || player_id >= MAX_PLAYERS) {
        printf("Invalid player ID\n");
        return;
    }
    world->players[player_id].x = new_x;
    world->players[player_id].y = new_y;
}