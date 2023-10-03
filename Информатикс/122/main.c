#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,a,b,i;
    scanf("%d",&n);
    scanf("%d",&m);
    i=0;
    a=1<<n;
    b=1<<m;
    printf("%d",(i|a)|b);
}
