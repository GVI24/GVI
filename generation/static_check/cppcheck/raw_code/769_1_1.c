// Vulnerability: Potential buffer overflow due to direct sizeof use in memcpy.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LANGUAGE_LENGTH 10
#define MAX_COUNTRY_LENGTH 5
#define BUFFER_SIZE 24
void createLocaleB(const char *langRegion) {
    char locale[BUFFER_SIZE];
    const char *charset = ".utf8";
    if (!langRegion) {
        return;
    }

    // Use sizeof on the source, not considering the destination size
    memcpy(locale, langRegion, sizeof(langRegion));
    memcpy(locale + strlen(locale), charset, sizeof(charset)); // May overflow

    setlocale(LC_ALL, locale);
}
