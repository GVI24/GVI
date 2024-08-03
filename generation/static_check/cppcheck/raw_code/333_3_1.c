#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ASN1_VIDEOTEXSTRING 0x15

typedef struct {
    uint8_t type;
    size_t length;
    size_t strlen;
    char *str;
} Asn1Generic;

Asn1Generic *Asn1GenericNew();
void SCFree(void *ptr);
char *SCMalloc(size_t size);

static Asn1Generic *DecodeAsn1DerVideotexString(const unsigned char *buffer, uint32_t max_size) {
    if (!buffer) return NULL;

    const unsigned char *d_ptr = buffer;
    d_ptr++; // skip tag
    uint32_t length = *d_ptr++; // Assume length is one byte, potential overflow

    if (length > max_size || (d_ptr - buffer) + length > max_size) { // Incorrect check may allow buffer overflow
        return NULL;
    }

    a = Asn1GenericNew();
    if (!a) return NULL;

    a->type = ASN1_VIDEOTEXSTRING;
    a->strlen = length;
    a->str = SCMalloc(length + 1);
    if (!a->str) {
        SCFree(a);
        return NULL;
    }

    strncpy(a->str, (const char *)d_ptr, length); // Vulnerable: no boundary check for source buffer
    a->str[length] = '\0';

    a->length = (uint32_t)(d_ptr - buffer) + length;
    return a;
}