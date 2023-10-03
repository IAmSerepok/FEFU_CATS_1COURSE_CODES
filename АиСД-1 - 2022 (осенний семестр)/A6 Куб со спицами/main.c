#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=0,j=0,z=0;
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");
    fscanf(inp,"%d",&n);
        while(z<n)
    {
        while(j<n)
    {
        while(i<n)
        {
            fprintf(outp,"%d ",(i+j+z)%n+1);
            i++;
        }
        i=0;
        fprintf(outp,"\n");
        j++;
    }
    j=0;
    z++;
    }
    fclose(inp);
    fclose(outp);
}
