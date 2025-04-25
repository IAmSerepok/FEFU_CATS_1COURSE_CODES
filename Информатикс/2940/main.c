#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v,t;
    scanf("%d",&v);
    scanf("%d",&t);
    if (v>=0)
    {
        printf("%d",(v*t)%109);
    }
    else
    {
        printf("%d",((109+(v*t)%109)%109));
    }
}
