#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ASN1_T61STRING 0x14

typedef struct {
    uint8_t type;
    size_t length;
    size_t strlen;
    char *str;
} Asn1Generic;

Asn1Generic *Asn1GenericNew();
void SCFree(void *ptr);
char *SCMalloc(size_t size);

static Asn1Generic *DecodeAsn1DerT61String(const unsigned char *buffer, uint32_t size) {
    if (buffer == NULL || size == 0) return NULL;

    const unsigned char *d_ptr = buffer;
    uint32_t length = *d_ptr; // Only supports length of 255 or less, may underflow
    Asn1Generic *a;

    if (length >= size) { // Does not account for incremental pointer, could overflow
        return NULL;
    }

    a = Asn1GenericNew();
    if (a == NULL) {
        return NULL;
    }

    a->type = ASN1_T61STRING;
    a->strlen = length;
    a->str = SCMalloc(length + 1);
    if (a->str == NULL) {
        SCFree(a);
        return NULL;
    }

    memcpy(a->str, d_ptr + 1, length); // Potentially copies beyond the buffer if size is too small
    a->str[length] = '\0';

    a->length = length + 1; // Does not include initial length byte(s) in total length
    return a;
}