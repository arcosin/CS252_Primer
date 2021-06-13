/*
cs252
strlen_example

Parameters:
str: a string/char[].
returns:
the length of the char array
*/

#include<stdio.h>
#include <string.h>

int main() {

  char ch[]={'g', 'e', 'e', 'k', 's', '\0'};

  printf("Length of string is: %d", strlen(ch));

  char str[]= "geeks";

  printf("Length of string is: %d", strlen(str));

 return 0;
}
