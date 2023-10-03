#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, r, i2 = 0, i5 = 0, c;
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");
    fscanf(inp,"%d %d", &a, &b);
    c = b;

    while ((a != 0) & (b != 0))
    {
        if (a >= b)
            a = a % b;
        else
        b = b % a;
    }
    r = a + b;
    c /= r;

    for(; c % 2 == 0; i2++)
        c /= 2;

    for(; c % 5 == 0; i5++)
        c /= 5;

    if(i2 >= i5)
        fprintf(outp, "%d %d", c, i2);
    else
        fprintf(outp, "%d %d", c, i5);
}
