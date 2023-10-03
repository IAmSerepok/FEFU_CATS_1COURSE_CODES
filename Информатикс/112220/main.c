#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,r,i=0;
    scanf("%d",&a);
    scanf("%d",&b);
    while ((a!=0) & (b!=0))
    {
        if (a>=b) a=a%b;
        else b=b%a;
        i++;
    }
    if (a>=b) r=a;
        else r=b;
    printf("%d %d",r,i);
}
