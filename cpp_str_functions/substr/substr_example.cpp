/*
cs252
substr_example

Parameters:
pos: position of the first character to be copied as a substring.
len: Number of characters to include in the substring

returns:
A string object with a substring of this object.
*/
#include <iostream>
#include <string>

int main () {
  std::string str="We think in gustavo, but we live in code.";

  // "think"
  std::string str2 = str.substr (3,5);     
  // "think"
  std::size_t pos = str.find("live");
  // position of "live" in str
  std::string str3 = str.substr (pos);
  // get from "live" to the end
  std::cout << str2 << ' ' << str3 << '\n';

  return 0;
}
