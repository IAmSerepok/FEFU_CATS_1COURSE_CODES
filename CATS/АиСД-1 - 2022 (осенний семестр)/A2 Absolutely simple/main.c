#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i=0;
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");
    fscanf(inp,"%d",&a);
    if (a==0) fprintf(outp,"%d",2);
    else
    {
    if (a<0)
    {
        a=(-1)*a+100;
        i++;
    }
    if (a%100==0)
    {
        fprintf(outp,"%d",a/100+1+i);
    }
    else
    {
        if (a%50==0)
        {
            fprintf(outp,"%d",a/100+1+i);
        }
        else fprintf(outp,"%d",a/100+2+i);
    }
    }
    fclose(inp);
    fclose(outp);
}
