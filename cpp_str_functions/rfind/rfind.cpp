/*
cs252
rfind_example

Parameters:
str: Another string with the subject to search for.
int: Position of the last character in the string to be considered as the beginning of a match.
key :Pointer to an array of characters.
int2: Length of sequence of characters to match.

returns:
The position of the first character of the last match.
*/
#include <iostream>
#include <string>
#include <cstddef>

int main ()
{
  std::string str ("The CS252 ta is bald from CS252.");
  std::string key ("CS252");
  std::cout << str << '\n';
  std::cout << key << '\n';

  std::size_t found = str.rfind(key);
  if (found!=std::string::npos)
    str.replace (found,key.length(),"gustavo");

  std::cout << str << '\n';

  return 0;
}
