#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");

    int v[2001]={};

    int n, buff;
    fscanf(inp, "%d", &n);

    for(int i = 0;i < n; i++){
        fscanf(inp, "%d", &buff);
        v[buff+1000]++;
    }

    for(int j = 0; j <2001; j++){
        if(v[j]!=0){
        fprintf(outp,"%d %d\n", j - 1000, v[j]);
    }
    }
}
