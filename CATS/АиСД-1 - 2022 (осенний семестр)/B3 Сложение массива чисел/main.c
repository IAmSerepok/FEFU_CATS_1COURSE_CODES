#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,i=0,res=0;
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");
    fscanf(inp,"%d",&n);
    while(i<n)
    {
        fscanf(inp,"%d",&a);
        res+=a;
        i++;
    }
    fprintf(outp,"%d",res);
    fclose(inp);
    fclose(outp);
}
