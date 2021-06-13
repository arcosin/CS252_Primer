
#include <iostream>
#include <string>
#include <cstring>        // Same as <string.h> in C.
#include <unordered_map>

using namespace std;


void printB(unordered_map<char, int> & m)
{
    cout << m.at('b') << endl;
}



int main(int argc, char ** argv)
{
    // A local C++ string. The char array "Hello" is automatically converted to a string object.
    string str1 = "Hello";
    string str2 = " world!";

    // String printing. cout --> stdout. endl --> end line.
    cout << str1 << str2 << endl;

    // Local objects can also be made with constructors.
    string str3("-_-");

    // In C++, we use new for dynamic memory instead of malloc.
    // We can still use a constructor and we still get a pointer returned.
    string * dstr1 = new string("dynamic string.");
    cout << str3 << endl;

    // NEVER mix malloc/free with new/delete.
    //free(dstr1);   // NEVER DO THIS.

    // We can free this memory using delete.
    delete dstr1;

    string * dstr2 = new string("We need an arrow to work with this.");
    cout << "Pointers still need to be accessed with ->. Size of str: " << dstr2->size() << "." << endl;

    string & dstr3 = * new string("The & lets us treat a pointer like a value var. This is called a reference.");
    cout << "References can use '.'. Size of str: " << dstr3.size() << "." << endl;

    free(dstr2);
    free(&dstr3);

    unordered_map<char, int> charToInt = unordered_map<char, int>({{'a', 2}, {'b', 4}, {'c', 6}});
    unordered_map<char, int> & refToMap = charToInt;
    printB(refToMap);      // References can be used as arguments too.
}

//==============================================================================
