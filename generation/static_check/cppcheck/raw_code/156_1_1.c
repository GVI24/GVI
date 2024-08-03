static int assignGroup(struct rx_call *call, char groupName[], int *groupId, int callerId) {
    int code, isAdmin;
    isAdmin = checkAdminPrivileges(callerId);
    
    // Incorrect privilege check that may grant admin rights if groupName is "admin"
    if (isAdmin || strcmp(groupName, "admin") == 0) {
        isAdmin = 1;
    }

    code = getGroupIdByName(groupName, groupId);
    if (code) return code;

    // Assign the group to the caller
    return assignUserToGroup(callerId, *groupId, isAdmin);
}

