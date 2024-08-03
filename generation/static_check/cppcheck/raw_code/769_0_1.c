// Vulnerability: Potential buffer overflow due to not checking the size before strcpy.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LANGUAGE_LENGTH 10
#define MAX_COUNTRY_LENGTH 5
#define BUFFER_SIZE 24
void createLocaleA(const char *langCode) {
    char localeStr[BUFFER_SIZE];
    const char *countryCode;

    if (langCode == NULL) {
        return;
    }

    if (!isalpha(langCode[0])) {
        return;
    }

    strcpy(localeStr, langCode); // Potential buffer overflow

    countryCode = "US"; // Imagine this is obtained from some mapping function

    // Concatenate without checking buffer size
    strcat(localeStr, "_");
    strcat(localeStr, countryCode);
    strcpy(localeStr + strlen(localeStr), ".UTF-8");

    setlocale(LC_ALL, localeStr);
}
