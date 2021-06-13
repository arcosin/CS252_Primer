/*
cs252
strcmp_example

Parameters:
str1: string/char[] 1
str2: string/char[] 2

returns:
If the value of str1 is greater than that of str2 than it will return a value greater than 0
If the value of str1 is less than that of str2 than it will return a value less than 0

*/
#include <stdio.h>
#include <string.h>

int main() {
    // Take any two strings
    char str1[] = "cs252!!";
    char str2[] = "cs252";

    // Compare strings using strcmp()
    int result2 = strcmp(str1, str2);

    if (result2 == 0)
        printf("str1 is equal to str2\n");
    else if (result2 > 0)
        printf("str1 is greater than str2\n");
    else
        printf("str2 is greater than str1\n");

    printf("Value returned by strcmp() is: %d", result2);

    return 0;
}
