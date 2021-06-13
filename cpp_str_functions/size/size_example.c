/*
cs252
size_example

Parameters:
none

returns:
The number of bytes in the string.
*/
#include <iostream>
#include <string>

int main () {
  std::string str ("Test string");
  std::cout << "The size of str is " << str.size() << " bytes.\n";
  return 0;
}
