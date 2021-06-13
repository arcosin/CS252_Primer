/*
cs252
strcat_example

Parameters:
str3: string/char[] pointer that will be appended
str2: string to append to the dest string
n: The first n character copied from src to dest.
returns:
the combination of the two strings from the n characters
*/

#include<stdio.h>
#include<string.h>

int main() {
   char str1[ 20 ] = "Hello "; //initialize str1
   char str2[ ] = "World !!! "; //initialize str2
   char str3[ 50 ] = "test "; //initialize str3 to empty

   //concatenate first 6 characters of str2 to str3
   printf("strncat(str3, str2, 6) = %s\n\n", strncat(str3, str2, 6));

   return 0;
}
