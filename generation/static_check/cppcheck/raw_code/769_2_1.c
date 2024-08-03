// Vulnerability: No bounds checking before strcat.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LANGUAGE_LENGTH 10
#define MAX_COUNTRY_LENGTH 5
#define BUFFER_SIZE 24
void createLocaleC(const char *language, const char *country) {
    char localeString[BUFFER_SIZE];

    if (language == NULL || country == NULL) {
        return;
    }

    // No bounds checking before concatenation
    strcat(localeString, language);
    strcat(localeString, "_");
    strcat(localeString, country);
    strcat(localeString, ".UTF-8");

    setlocale(LC_ALL, localeString);
}
