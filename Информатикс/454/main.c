#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, d, x1, y1, x2, y2;
    scanf("%f %f %f %f %f %f %f %f", &a, &b, &c, &d, &x1, &y1, &x2, &y2);

    float x0 = (x1-a)/(c-a), y0 = (y1-b)/(d-b),
          x = x2*(c-a)+a, y = y2* (d-b)+b;

    printf("%.3f %.3f %.3f %.3f", x0, y0, x, y);
}
