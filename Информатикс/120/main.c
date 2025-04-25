#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j=1;
    float res=1;
    scanf("%d",&n);
    while(j<=n)
    {
        if (n>=8)
    {
        res=2.71828;
        break;
    }
        int fact=1;
        for (i = 1; i <= j; ++i)
        {
            if (n>=8)
    {
        res=2.71828;
        break;
    }
            fact *= i;
        }
        float a =(1./fact);
        res+=a;
        j++;
    }
    printf("%.5f",res); //e=2,7...
}
