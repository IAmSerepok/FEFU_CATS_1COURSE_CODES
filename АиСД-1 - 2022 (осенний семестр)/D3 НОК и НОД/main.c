#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    int a,b,nod,i,a0, b0;
    fscanf(inp, "%d",&a);
    fscanf(inp, "%d",&b);

    a0 = a;
    b0 = b;

    while ((a!=0) & (b!=0))
    {
        if (a>=b) a=a%b;
        else b=b%a;
        i++;
    }

    nod=a+b;

    int nok = a0*b0/nod;
    fprintf(outp, "%d %d", nod, nok);
}
