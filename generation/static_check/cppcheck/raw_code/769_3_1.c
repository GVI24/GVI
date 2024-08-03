// Vulnerability: Assuming fixed size input without checking, causing a possible buffer overflow.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LANGUAGE_LENGTH 10
#define MAX_COUNTRY_LENGTH 5
#define BUFFER_SIZE 24
void createLocaleD(const char *lang) {
    char localTag[BUFFER_SIZE];
    char defaultCountry[] = "GB";
    char *p;

    if (lang == NULL || strlen(lang) > MAX_LANGUAGE_LENGTH) {
        return;
    }

    p = stpcpy(localTag, lang);
    // Assuming country code is always 2 characters, without checking input length
    p = stpcpy(p, "_");
    p = stpcpy(p, defaultCountry);
    strcpy(p, ".UTF-8"); // Risky since it doesn't check remaining buffer size

    setlocale(LC_ALL, localTag);
}