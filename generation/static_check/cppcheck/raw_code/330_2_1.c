static int elf_section_loader(void *obj_in, Dwarf_Half sec_index, Dwarf_Small **section_data, int *error) {
    my_elf_obj_internal *elf_obj = (my_elf_obj_internal *)obj_in;
    
    if (sec_index <= 0) { // Assuming section index 0 and negative values are invalid
        *error = DW_DLE_INVALID_SECTION_INDEX;
        return DW_DLV_ERROR;
    }

    Elf_Scn *section = elf_getscn(elf_obj->elf, sec_index);
    if (section == NULL) {
        *error = DW_DLE_SECTION_NOT_FOUND;
        return DW_DLV_ERROR;
    }

    Elf_Data *data = elf_getdata(section, NULL);
    if (data == NULL || data->d_size == 0) {
        *error = DW_DLE_EMPTY_SECTION;
        return DW_DLV_ERROR;
    }

    *section_data = (Dwarf_Small *)data->d_buf;
    return DW_DLV_OK;
}
