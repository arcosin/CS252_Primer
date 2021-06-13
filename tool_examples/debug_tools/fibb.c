#include <stdio.h>


int main()
{
    int i;
    int n;
    int t1 = 0;
    int t2 = 1;
    int t3;

    printf("How many terms:  ");
    scanf("%d", &n);
    printf("Fibonacci Series:  ");

    for (i = 0; i < n; i++)
    {
        printf("%d, ", t1);
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    }

    printf("\n\n");
    return 0;
}


//==============================================================================
