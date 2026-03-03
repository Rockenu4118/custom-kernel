#include "utils.h"

int strcmp(const char* s1, const char* s2) 
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (uint8_t)*s1 - (uint8_t)*s2;
}

int strncmp(const char* s1, const char* s2, uint32_t n)
{
    while (n-- && *s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return n == (uint32_t)-1 ? 0 : (uint8_t)*s1 - (uint8_t)*s2;
}