/*
cs252
strcpy_example

Parameters:
src: The string to be copied.
dest: Pointer for where the src is to be copied.
returns:

*/

#include <stdio.h>
#include <string.h>
int main() {
    char src[] = "CS252";

    // Here destination is large enough
    // to store the src with Null
    // character at the end
    char dest[14];

    // copying src into dest.
    strcpy(dest, src);
    printf("Copied string: %s\n", dest);

    return 0;
}
