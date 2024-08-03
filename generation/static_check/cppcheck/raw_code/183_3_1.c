// Example of a potential format string vulnerability
void log_message(lua_State *L) {
    const char *message = luaL_checkstring(L, 1);
    char log_buffer[256];
    // Unsafe use of user-supplied string in a format-specifier context
    sprintf(log_buffer, message);
    fputs(log_buffer, stderr);
}