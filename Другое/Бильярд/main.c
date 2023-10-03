#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,nod,i,h,l=0;
    scanf("%d",&a);
    scanf("%d",&b);

    if(a>b){
           l=a;
           h=b;
       }else{
       l=b;
       h=a;
       }

    while ((a!=0) & (b!=0))
    {
        if (a>=b) a=a%b;
        else b=b%a;
        i++;
    }

    nod=a+b;
    l=l/nod;
    h=h/nod;
    printf("%d",l+h-2);
}
