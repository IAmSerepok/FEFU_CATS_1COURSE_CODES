#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a;
    int h,m,s,k;
    scanf("%f",&a);
    h=floor(a/30);
    m=floor(a*2);
    m=m%60;
    s=floor(a*120);
    k=floor(a);
    printf("%d %d %d",h,m%60,s%60);
}
