/*
cs252
strncpy_example

Parameters:
src: The string to be copied.
dest: Pointer for where the src is to be copied.
n: The first n character copied from src to dest.
returns:

*/

#include <stdio.h>
#include <string.h>
int main() {
    char src[] = "CS252";

    // The destination sting size is 8
    // which is less than length of src.
    char dest[5];

    // copying 8 bytes of src into dest.
    // dest is not NULL terminated.
    strncpy(dest, src, 5);

    // using strlen function on non terminated.
    // string which can cause segfault.
    int len = strlen(dest);

    printf("Copied string: %s\n", dest);
    printf("Length of destination string: %d\n", len);

    return 0;
}
