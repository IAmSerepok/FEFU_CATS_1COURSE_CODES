#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,l,h,a,b;
    l=0;
    k=0;
    scanf("%d",&h);
    scanf("%d",&a);
    scanf("%d",&b);
    while(l<h)
    {
        k++;
        l=l+a;
        if(l>=h) printf("%d",k);
        else l=l-b;
    }
}
