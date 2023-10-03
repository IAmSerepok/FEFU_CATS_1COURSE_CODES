#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    double x1, y1, x2, y2, x0, y0, angle, mod1, mod2, x1r, y1r, x2r, y2r;

    fscanf(inp, "%lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x0, &y0, &angle);

    angle = angle * M_PI / 180;

    if(x1 != x0 || y1 != y0){
    x1 -= x0;
    y1 -= y0;

    mod1 = sqrt(x1*x1+y1*y1);

    x1 /= mod1;
    y1 /= mod1;

    x1r = x1*cos(angle) - y1*sin(angle);
    y1r = x1*sin(angle) + y1*cos(angle);

    x1r *= mod1;
    y1r *= mod1;

    x1r += x0;
    y1r += y0;
    }
    else{

        x1r = x1;
        y1r = y1;
    }

    if(x2 != x0 || y2 != y0){
    x2 -= x0;
    y2 -= y0;

    mod2 = sqrt(x2*x2+y2*y2);

    x2 /= mod2;
    y2 /= mod2;

    x2r = x2*cos(angle) - y2*sin(angle);
    y2r = x2*sin(angle) + y2*cos(angle);

    x2r *= mod2;
    y2r *= mod2;

    x2r += x0;
    y2r += y0;
    }

    else{

        x2r = x2;
        y2r = y2;
    }

    fprintf(outp, "%.3lf %.3lf %.3lf %.3lf\n", x1r, y1r, x2r, y2r);
}
