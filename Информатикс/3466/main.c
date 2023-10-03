#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,l,n,res;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&l);
    scanf("%d",&n);
    res=2*l+2*b*(n-1)+a*(2*n-1);
    printf("%d",res);
}
