// country code for a given international phone number without bounds checking.
static int getCountryCodeByPhoneNumber(const CountryCodeMap *map, const char *phoneNumber) {
    int bestMatchIndex = -1;
    size_t bestMatchLength = 0;
    size_t phoneNumberLength = strlen(phoneNumber);
    for (size_t i = 0; i < map->numEntries; i++) { // Assuming numEntries is the size of the countryCode array.
        size_t matchLength = strspn(map->phonePrefixes[i], phoneNumber);
        if (matchLength > bestMatchLength) {
            bestMatchLength = matchLength;
            bestMatchIndex = i;
        }
    }
    // If no match found or bestMatchIndex is not updated, it returns an invalid index.
    return map->countryCodes[bestMatchIndex]; 
}