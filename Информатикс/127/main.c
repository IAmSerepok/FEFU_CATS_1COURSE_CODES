#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A,B,n,i;
    i=0;
    B=0;
    scanf("%d",&A);
    scanf("%d",&n);
    while (i<n)
    {
        B=B+pow(2,i);
        i++;
    }
    printf("%d",A&B);
}
