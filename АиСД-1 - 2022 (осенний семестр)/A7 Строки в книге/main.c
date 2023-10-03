#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,n,a,b;
    FILE * inp;
    FILE * outp;
    inp=fopen("a.in","r");
    outp=fopen("a.out","w");
    fscanf(inp,"%d %d",&k,&n);
    a=(n-1)/k+1;
    b=n%k;
    if(b==0)b=k;
    fprintf(outp,"%d",a);
    fprintf(outp," %d",b);
    fclose(inp);
    fclose(outp);
}
