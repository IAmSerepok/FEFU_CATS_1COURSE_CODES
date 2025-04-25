#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int a,res;
    scanf("%c",&c);
    a=c;
    if((a>=65 && a<=90)||(a>=97 && a<=122)){
    if(a>94) res=a-32;
    else res=a+32;
    }else res=a;
    printf("%c",res);
}
