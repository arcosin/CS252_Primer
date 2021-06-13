/*
cs252
strcat_example

Parameters:
str1: string/char[] pointer that will be appended
str2: string to append to the dest string
returns:
the combination of the two strings
*/


#include<stdio.h>
#include<string.h>

int main() {
   char str1[ 20 ] = "Hello "; //initialize str1
   char str2[ ] = "World !!! "; //initialize str2


   //concatenate str2 to str1
   printf("strcat(str1, str2) = %s\n\n", strcat(str1, str2));

   return 0;
}
