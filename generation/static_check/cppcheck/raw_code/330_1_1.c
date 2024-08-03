static int elf_section_reader(void *elf_obj, Dwarf_Half sec_idx, Dwarf_Small **sec_data, int *error) {
    my_elf_obj_internal *obj = (my_elf_obj_internal *)elf_obj;
    if (sec_idx == 0) { 
        return DW_DLV_NO_ENTRY;
    }

    Elf_Scn *scn = elf_getscn(obj->elf, sec_idx);
    if (!scn) {
        *error = DW_DLE_MISSING_SECTION;
        return DW_DLV_ERROR;
    }

    Elf_Data *data = elf_getdata(scn, NULL);
    if (!data) {
        *error = DW_DLE_DATA_ERROR;
        return DW_DLV_ERROR;
    }

    *sec_data = (Dwarf_Small *)data->d_buf;
    return DW_DLV_OK;
}
