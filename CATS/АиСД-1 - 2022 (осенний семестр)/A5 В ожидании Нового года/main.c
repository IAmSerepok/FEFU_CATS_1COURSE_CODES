#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");
    fscanf(inp,"%d",&a);
    fscanf(inp,"%d",&b);
    a=(24-a);
    if(b!=0 & a!=0)
    {
        a--;
        b=(60-b);
    }
    if(a<0)a=0;
    fprintf(outp,"%d %d",a,b);
    fclose(inp);
    fclose(outp);
}
