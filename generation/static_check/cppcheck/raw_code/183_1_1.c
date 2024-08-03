// Example of a potential use-after-free vulnerability
void process_script(lua_State *L) {
    char *script_buffer = malloc(1024);
    const char *script = luaL_checkstring(L, 1);
    strncpy(script_buffer, script, 1024);
    free(script_buffer); // Buffer is freed

    // ... some code ...

    // Use-after-free occurs here
    for (int i = 0; script_buffer[i] != '\0'; i++) {
        printf("%c", script_buffer[i]);
    }
}