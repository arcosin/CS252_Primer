/*
cs252
strncmp_example

Parameters:
str1: string/char[] 1
str2: string/char[] 2
n: The first n character copied from src to dest.
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

    // Compare strings using strncmp()
    int result1 = strncmp(str1, str2, 4);

    // num is the 3rd parameter of strncmp() function
    if (result1 == 0)
        printf("str1 is equal to str2 upto num characters\n");
    else if (result1 > 0)
        printf("str1 is greater than str2\n");
    else
        printf("str2 is greater than str1\n");

    printf("Value returned by strncmp() is: %d\n", result1);


    return 0;
}
