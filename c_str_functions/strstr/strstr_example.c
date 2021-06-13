/*
cs252
strstr_example

Parameters:
str1: This is the main string to be examined.
str2: This is the sub-string to be searched in s1 string.
returns:
returns the first occurrence of the character
*/
#include <string.h>
#include <stdio.h>

int main() {
    // Take any two strings
    char str1[] = "cs252 is cs252";
    char str2[] = "cs252";
    char* p;

    // Find first occurrence of s2 in s1
    p = strstr(str1, str2);

    // Prints the result
    if (p) {
        printf("String found\n");
        printf("First occurrence of string '%s' in '%s' is '%s'", str1, str2, p);
    } else {
        printf("String not found\n");
    }

    return 0;
}
