/*
cs252
c_str_example

Parameters:
none

returns:
The pointer returned may be invalidated by further calls to other member
functions that modify the object.
*/
#include <iostream>
#include <cstring>
#include <string>

int main () {
  std::string str ("CS252 is Really good because of gustavo!!!");

  char * cstr = new char [str.length()+1];
  std::strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str

  char * p = std::strtok (cstr," ");
  while (p!=0) {
    std::cout << p << '\n';
    p = std::strtok(NULL," ");
  }

  delete[] cstr;
  return 0;
}
