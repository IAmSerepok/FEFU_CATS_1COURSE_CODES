#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,xn=1,sum=1;
    long long n,fact;

    scanf("%ld %lf",&n,&x);

    if(n<20){
    for(int i=0;i<n;i++){
        fact=1;

        for(int j=i+1;j>0;j--)
            fact*=j;

        xn*=x;
        sum+=xn/fact;
    }
    printf("%lf",sum);
    }
    else printf("%f",exp(x));
}
