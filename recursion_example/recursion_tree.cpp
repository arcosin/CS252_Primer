
#include <iostream>
#include <string>
#include <vector>

using namespace std;




/*
Goal: Create the tree below, and use recurion to print every full sentence combination.


            +-- world!
            |
    Hello --+-- my -- name -- is --+-- Max.
            |                      |
            |                      +-- a -- secret.
            |
            |           +-- students.
            |           |
            +-- CS252 --+-- TAs.
                        |
                        +-- professors.
*/




struct node
{
    string data;
    node * c1;
    node * c2;
    node * c3;
    node(const char * data, node * c1 = NULL, node * c2 = NULL, node * c3 = NULL)
    {
        this->data = data;
        this->c1 = c1;
        this->c2 = c2;
        this->c3 = c3;
    }
};

typedef node N;





string printAllSents(node * n, string prefix = "")
{
    if(n->c1 == NULL && n->c2 == NULL && n->c3 == NULL)   // Base case.
    {
        return prefix + n->data + "\n";
    }
    else                                                  // Recurion cases.
    {
        string agg = "";
        if(n->c1 != NULL)
        {
            agg = agg + printAllSents(n->c1, prefix + n->data);
        }
        if(n->c2 != NULL)
        {
            agg = agg + printAllSents(n->c2, prefix + n->data);
        }
        if(n->c3 != NULL)
        {
            agg = agg + printAllSents(n->c3, prefix + n->data);
        }
        return agg;
    }
}




void deleteTree(node * n)
{
    if(n->c1 != NULL)             // Base case is implicitly when no child is non-null.
    {
        deleteTree(n->c1);
    }
    if(n->c2 != NULL)
    {
        deleteTree(n->c2);
    }
    if(n->c3 != NULL)
    {
        deleteTree(n->c3);
    }
    delete n;                     // Delete after recursion for bottom-up deletion.
}




int main(int argc, char ** argv)
{
    N * root = new N("Hello", new N(" world!"), new N(" my", new N(" name", new N(" is", new N(" Max."), new N(" a", new N(" secret."))))), new N(" CS252", new N(" students."), new N(" TAs."), new N(" professors.")));
    cout << printAllSents(root);
    deleteTree(root);
}
