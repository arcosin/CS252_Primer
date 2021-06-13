/*
cs252
strdup_example

Parameters:
src: The string to be duplicated.
returns:
pointer to the new char array
*/
#include<stdio.h>
#include<string.h>

int main() {
    char source[] = "CS252";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = strdup(source);

    printf("%s", target);
    return 0;
}
