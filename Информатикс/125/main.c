#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,i,res;
    scanf("%d",&A);
    scanf("%d",&i);
    B=1<<i;
    res=A^B;
    printf("%d",res);
}
