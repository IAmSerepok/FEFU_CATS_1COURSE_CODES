#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    double d = (x3-x1)*(y2-y1)-(y3-y1)*(x2-x1);

    if(d==0) printf("BOTH");
    if(d>0) printf("RIGHT");
    if(d<0) printf("LEFT");
}
