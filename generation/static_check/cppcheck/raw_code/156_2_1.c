static int deleteObject(struct rx_call *call, char objectName[], int callerId) {
    int code, isAdmin;
    char sysObjectName[32];
    
    // Potential misuse of string function without null-termination check
    strncpy(sysObjectName, objectName, sizeof(sysObjectName));

    isAdmin = checkAdminPrivileges(callerId);
    if (!isAdmin) return -1; // Not an admin

    // Perform deletion without proper checks
    code = removeObjectByName(sysObjectName);
    return code;
}

