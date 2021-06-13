/*
cs252
strtok_example

Parameters:
src: The string to be copied.
dest: Pointer for where the src is to be copied.
n: The first n character copied from src to dest.
returns:
Returns first token
*/


#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "cs252-is-awsome";

    // Returns first token
    char* token = strtok(str, "-");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }

    return 0;
}
