#include <stdio.h>
#include <stdlib.h>

int main()
{
    float xa, ya, xb, yb, xc, yc, k;
    scanf("%f %f %f %f %f %f %f", &xa, &ya, &xb, &yb, &xc, &yc, &k);

    float x1 = xa+k*(xb-xa), x2 = xa+k*(xc-xa),
        y1 = ya+k*(yb-ya), y2 = ya+k*(yc-ya);

    printf("%.5f %.5f\n%.5f %.5f", x1, y1, x2, y2);
}
