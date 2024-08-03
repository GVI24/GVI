// Example 2
static int allocate_texture(TextureManager *tm) {
    int index;
    for (index = 0; index <= tm->max_textures; index++) {
        if (tm->textures[index].data == NULL) {
            tm->textures[index].data = (char*)malloc(TEXTURE_SIZE);
            return index;
        }
    }
    return -1;
}