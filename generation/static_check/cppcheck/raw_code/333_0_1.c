#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint8_t type;
    size_t length;
    size_t strlen;
    char *str;
} Asn1Generic;

Asn1Generic *Asn1GenericNew();
void SCFree(void *ptr);
char *SCMalloc(size_t size);

static Asn1Generic *DecodeAsn1DerPrintableString(const unsigned char *buffer, uint32_t max_size) {
    const unsigned char *d_ptr = buffer;
    uint32_t length;
    Asn1Generic *a;

    length = *d_ptr++; // Assume first byte is length

    if (length > max_size) {
        return NULL;
    }

    a = Asn1GenericNew();
    if (a == NULL) {
        return NULL;
    }

    a->type = 0x13; // ASN.1 PrintableString tag
    a->strlen = length;
    a->str = SCMalloc(length + 1);
    if (a->str == NULL) {
        SCFree(a);
        return NULL;
    }

    memcpy(a->str, d_ptr, length); // Vulnerable: no boundary check for source buffer
    a->str[length] = '\0';
    
    a->length = (uint32_t)(d_ptr - buffer) + length;
    return a;
}