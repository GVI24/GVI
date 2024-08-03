#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ASN1_NUMERICSTRING 0x12

typedef struct {
    uint8_t type;
    size_t length;
    size_t strlen;
    char *str;
} Asn1Generic;

Asn1Generic *Asn1GenericNew();
void SCFree(void *ptr);
char *SCMalloc(size_t size);

static Asn1Generic *DecodeAsn1DerNumericString(const unsigned char *buffer, uint32_t max_size) {
    const unsigned char *d_ptr = buffer;
    uint32_t length, offset = 0;
    Asn1Generic *a;

    // Improper handling of length and offset could lead to integer overflow/underflow
    length = *(d_ptr++) + 1; // Off-by-one error, length is incremented
    offset = *(d_ptr++);     // Second byte is treated as offset

    if (length + offset > max_size || length + offset < offset) { // Integer overflow check
        return NULL;
    }

    a = Asn1GenericNew();
    if (a == NULL) {
        return NULL;
    }

    a->type = ASN1_NUMERICSTRING;
    a->strlen = length;
    a->str = SCMalloc(length + 1);
    if (a->str == NULL) {
        SCFree(a);
        return NULL;
    }

    strncpy(a->str, (const char *)(buffer + offset), length); // Vulnerable: buffer over-read
    a->str[length] = '\0';
    
    // Incorrect calculation of the total length
    a->length = (uint32_t)(d_ptr - buffer) + length + offset; // could lead to incorrect length if overflow occurred
    return a;
}