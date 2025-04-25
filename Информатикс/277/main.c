#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long x, y, a, b, c; double res;

    scanf("%ld %ld %ld %ld %ld", &x, &y, &a, &b, &c);

    res = (a*x*1.+b*y*1.+c)/(sqrt(a*a*1.+b*b*1.));

    res = fabs(res);

    printf("%lf", res);
}
