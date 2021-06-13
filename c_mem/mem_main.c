
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    _________________
    |_______________|            Args, envars, etc.
    |               |
    |       E       |            Stack, growing downward.
    |               |
    | v v v v v v v |
    |               |
    |               |
    |      ...      |
    |               |
    |               |
    |               |
    | ^ ^ ^ ^ ^ ^ ^ |
    |               |
    |       D       |            Heap, growing upward.
    |_______________|
    |               |
    |       C       |            Uninitialized Data (BSS).
    |_______________|
    |               |
    |       B       |            Initialized Data.
    |_______________|
    |               |
    |       A       |            Text.
    |_______________|
*/




// Global memory. Initialized before main() is called. Stored in section B.
int globalX = 5;

// Uninitialized global memory. Stored in section C and all bytes zeeroed out.
int globalY;

// Also global memory, but may be stored in a special read-only part of section A.
const char * constGlobal = "This string cannot be changed.";


struct Item
{
  int a;        // 4 bytes.
  char b;       // 1 bytes.
  char c;       // 1 bytes.
  char d;       // 1 bytes.
  char e;       // 1 bytes.
};              // Total: 8 bytes.



// Helper function to print int lists.
// Notice we take the list as a pointer.
// This is because pointers are arrays in C are the same concept.
void printList(const char * name, int * listPointer, int listSize)
{
    printf("%s = [", name);
    for(int i = 0; i < listSize; i++)
    {
        printf("%d,", listPointer[i]);
    }
    printf("]\n");
}



// Shows how NOT to return memory.
/*
char * badStrFunction()
{
    char woot [11];
    strcpy(woot, "woot woot!");
    return woot;
}
*/



char * goodStrFunction()
{
    char * woot = strdup("woot woot ;)!");   // Strdup calls malloc inside.
    return woot;
}




int main(int argc, char ** argv)
{
    // This string is a local variable and lives in section E (the stack).
    // It will not continue existing outside of the function.
    char * localStr = "This string is on the stack.";

    // Primitive types (like single chars, ints, floats, etc) can be moved around with stack memory without worry.
    // C's pass-by-value default makes this possible.

    // This can be done with any variable type so long as the size is known upon initialization.
    int stackIntList1 [8];
    int stackIntList2 [] = {10, 20, 35, 100};
    unsigned int stackIntList3 [] = {12345, 0, 25, 1094795585};    // Bytes: [0,0,48,57],[0,0,0,0],[0,0,0,25],[65,65,65,65]

    // For these print calls, we pass the local pointer in as an argument.
    // This is OK because this call is done from within the "home scope" of the list variable.
    // This would not be the case with something like a return.
    printList("stackList1", stackIntList1, 8);
    printList("stackList2", stackIntList2, 4);

    // This won't work safely because "woot woot!\n" is no longer on the stack after badStrFunction returns.
    //char * s = badStrFunction();
    //printf("%s\n", s);

    // This is why we have dynamic memory allocated with malloc / calloc / realloc.
    // Dynamic memory lives on the heap (section D) and persists until freed.
    int * mallocedIntList = (int *) malloc(5 * sizeof(int));
    printList("mallocedIntList", mallocedIntList, 5);
    free(mallocedIntList);

    // This won't work because mallocedIntList has already been freed.
    // Bugs like this are nondeterministic and hard to find.
    //printList("mallocedIntList", mallocedIntList, 5);

    // We can make it easiier on ourselves by setting mallocedIntList pointer to null.
    // That way, we get a segfault by accessing it after free.
    mallocedIntList = NULL;

    int * callocedIntList = (int *) calloc(5, sizeof(int));
    printList("callocedIntList", callocedIntList, 5);
    free(callocedIntList);

    // And now we can do this.
    char * s = goodStrFunction();
    printf("%s\n", s);

    // If we don't free dynamic memory, we will get a memory leak.
    // This can hurt your program in the long term, and make you lose points in class.
    // Remember, only free dynamic memory (that comes from malloc, calloc, realloc, strdup, etc).
    free(s);

    int x = 25;
    int * xp = &x;   // Pointer to x (in stack).

    printf("X value:  %d.\n", *xp);     // Dereferencing the pointer.
    printf("X value:  %d.\n", xp[0]);   // Also dereferencing the pointer (exact same functionality).

    // Modification by pointer.
    *xp = 10;
    printf("New X value:  %d.\n", *xp);

    xp[0] = 13;
    printf("New new X value:  %d.\n", xp[0]);
    printf("New new X value from orig var:  %d.\n\n", x);

    // Types do not truly exist in memory.
    // By treating the int array as a char array, we can see what eeach byte value is.
    char * intAsBytes = (char *) stackIntList3;
    printf("Array stackIntList3 as bytes:\n");
    for(int i = 0; i < 16; i++)
    {
        printf("%d\n", intAsBytes[i]);
    }
    printf("\n");

    // This is not limited to primitive types.
    // Structs in C are an abstraction, a 'mask' grouping together related vars.
    struct Item * intAsItems = (struct Item *) stackIntList3;
    printf("Array stackIntList3 as Items:\n");
    for(int i = 0; i < 2; i++)
    {
        printf("a = %d.\n", intAsItems[i].a);
        printf("b = %c.\n", intAsItems[i].b);
        printf("c = %c.\n", intAsItems[i].c);
        printf("d = %c.\n", intAsItems[i].d);
        printf("e = %c.\n\n", intAsItems[i].e);
    }
}

//==============================================================================
