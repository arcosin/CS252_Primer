

#include <iostream>
#include <regex>


using namespace std;

/*
    To mess with regexes, go to https://regexr.com/.
*/


int main(int argc, char ** argv)
{
    string courses[] = {"Systems Programming",
                        "Dynamic Programming",
                        "Neural Image Processing",
                        "Programming Languages",
                        "Computer Arch",
                        "Competitive Programming",
                        "Advanced Neural Projects",
                        "Operating Systems"};

    regex reg("(.* Programming)");                                              // Look for strings like "[something] Programming".
    smatch matchBuf;                                                            // Holds the match.

    for(auto & c : courses)
    {
        if(regex_match(c, matchBuf, reg))                                       // Is there a match?
        {
            ssub_match subMatch = matchBuf[1];                                  // match[0] is always the whole string. match[1] is what is in the parens.
            string cName = subMatch.str();
            cout << cName << endl;
        }
    }

    regex reg2("Neural");                                                        // Look for strings including "Neural".
    cout << regex_replace(courses[2], reg2, "Neural Network") << endl;
    cout << regex_replace(courses[6], reg2, "Neural Network") << endl;
}

//==============================================================================
