// Example of a potential integer overflow leading to a buffer overflow
void load_data(lua_State *L) {
    int size;
    lua_Integer n = luaL_checkinteger(L, 1);
    if (n <= 0 || n > INT_MAX - 1) {
        luaL_error(L, "Invalid size");
        return;
    }

    size = (int)n;
    char *data = malloc(size + 1); // Potential integer overflow if n is INT_MAX
    if (data) {
        luaZ_fillbuffer(L, data, size);
        process_data(data, size);
        free(data);
    }
}