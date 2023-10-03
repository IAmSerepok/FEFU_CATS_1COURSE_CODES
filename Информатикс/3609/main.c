#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x;
    long long a,b;
    scanf("%lf",&x);
    a=floor(x)*10;
    b=floor(x*10);
    if(x>=0)printf("%d",b-a);
    else printf("%d",10-b+a);
}
