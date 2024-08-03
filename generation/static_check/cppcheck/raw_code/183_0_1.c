// Example of a potential buffer overflow vulnerability
void execute_command(lua_State *L) {
    char cmd_buffer[256];
    const char *command = luaL_checkstring(L, 1);
    strcpy(cmd_buffer, command); // Potential buffer overflow if command > 256 chars
    system(cmd_buffer);
}