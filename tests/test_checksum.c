#include <stdio.h>
#include <string.h>

// Calculate the checksum of an NMEA sentence
unsigned char calculate_checksum(const char *sentence) {
    unsigned char checksum = 0;
    int i;

    for (i = 0; sentence[i] != '*' && sentence[i] != '\0'; i++) {
        checksum ^= sentence[i];
    }

    return checksum;
}

// Verify the checksum of an NMEA sentence
int verify_checksum(const char *sentence, size_t length) {
    if (sentence[length - 3] != '*') {
        return 0; // Invalid sentence format
    }

    unsigned char expected_checksum;
    if (sscanf(sentence + length - 2, "%2hhx", &expected_checksum) != 1) {
        return 0; // Invalid checksum format
    }

    unsigned char calculated_checksum = calculate_checksum(sentence);
    return calculated_checksum == expected_checksum;
}

// Rest of your code remains the same
