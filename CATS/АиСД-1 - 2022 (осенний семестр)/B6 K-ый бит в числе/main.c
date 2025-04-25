#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");

    int x,k,res;
    fscanf(inp,"%d %d",&x,&k);

    for(int i=0;i<=k;k--){
        res=x%2;
        x/=2;
    }

    fprintf(outp,"%d",res);

    fclose(inp);
    fclose(outp);
}
