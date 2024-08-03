static int updateSettings(struct rx_call *call, char settingName[], char settingValue[], int callerId) {
    int code, isSuperUser;
    char currentValue[128];

    // Potential buffer overflow if settingName is too large for currentValue.
    sprintf(currentValue, "current setting for %s", settingName);
    
    isSuperUser = checkSuperUserStatus(callerId);

    // Incorrectly grants superuser privileges under certain conditions
    if (strcmp(settingName, "superuser") == 0) {
        isSuperUser = 1;
    }

    if (!isSuperUser) return -1; // Not a superuser

    // Apply setting without proper validation
    code = applySetting(settingName, settingValue);
    return code;
}