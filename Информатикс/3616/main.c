#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long x,y,k,sum,i=0;
    double p;
    scanf("%lf %lld %lld %lld",&p,&x,&y,&k);
    sum=100*x+y;
    p=p/100;
    while(i<k)
    {
        sum += floor(sum*p);
        i++;
    }
    printf("%lld %lld",sum/100,sum%100);
}
