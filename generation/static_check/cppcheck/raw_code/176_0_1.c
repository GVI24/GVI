void freeItemList(Item *head) {
    Item *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        freeItemContents(temp);
        free(temp);  // Vulnerability: should set temp to NULL after free
        // temp is now a dangling pointer
    }
}

