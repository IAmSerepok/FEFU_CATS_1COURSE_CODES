#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");

    int k, sum = 0, buff;
    fscanf(inp, "%d", &k);

    for(int j = 1; j < k; j++){
        int arr[6]={};
        int s=0;
        buff=j;
        int i = 1, z=0;
        while(buff>0){
            arr[i] = buff % 10;
            buff /= 10;
            i++;
            z++;
        }
    int per = 0;

    for(int zi = 1; zi <= z; zi++){
        per += pow(10,z-zi)*arr[zi];
    }
        if((per + j) == k)
            sum++;
    }
    fprintf(outp, "%d\n", sum);
}
