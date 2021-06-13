/*
cs252
copy_example

Parameters:
str1: Pointer to an array of characters.
int: Number of characters to copy
int2: Position of the first character to be copied.

returns:
The number of characters copied to the array pointed by s
*/
#include <iostream>
#include <string>

int main () {
  char str1[20];
  std::string str ("Test string...");
  int length = str.copy(str1,6,5);
  str1[length]='\0';
  std::cout << "str1 contains: " << str1 << '\n';
  return 0;
}
