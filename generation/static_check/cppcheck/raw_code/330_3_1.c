static int elf_section_fetch(void *object, Dwarf_Half section_num, Dwarf_Small **data_ptr, int *err_code) {
    my_elf_obj_internal *elf_internal = (my_elf_obj_internal *)object;
    
    if (section_num == 0) {
        return DW_DLV_NO_ENTRY;
    }

    Elf_Scn *scn = elf_getscn(elf_internal->elf, section_num);
    if (scn == NULL) {
        *err_code = DW_DLE_NO_ELF_RESOURCES;
        return DW_DLV_ERROR;
    }

    Elf_Data *data = elf_getdata(scn, NULL);
    if (data == NULL || data->d_buf == NULL) {
        *err_code = DW_DLE_DATA_NULL;
        return DW_DLV_ERROR;
    }

    *data_ptr = (Dwarf_Small *)data->d_buf;
    return DW_DLV_OK;
}