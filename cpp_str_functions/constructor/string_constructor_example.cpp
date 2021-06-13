/*
cs252
string_constructor_example

different ways to make c++ string and
print it out
*/
#include <iostream>
#include <string>

int main () {
  std::string s0 ("CS252 string");

  // constructors used in the same order as described above:
  std::string s1;
  std::string s2 (s0);
  std::string s3 (s0, 8, 3);
  std::string s4 ("A gustavo party of coding");
  std::string s5 ("Another gustavo party of codin", 12);
  std::string s6a (10, 'x');
  std::string s6b (10, 42);      // 42 is the ASCII code for '*'
  std::string s7 (s0.begin(), s0.begin()+7);

  std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
  std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';
  return 0;
}
