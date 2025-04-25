#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp = fopen("input.txt", "r");
    FILE * outp = fopen("output.txt", "w");

    int n, m, sum=0;
    fscanf(inp, "%d", &n);
    int arr[n+2];
    arr[0]=0;

    for(int i = 1; i < n+1; i++){
        int buff;
        fscanf(inp, "%d", &buff);
        sum += buff;
        arr[i] = sum;
    }

    fscanf(inp, "%d", &m);

    for(int i = 0; i < m; i++){

        int l, r;
        fscanf(inp, "%d", &l);
        fscanf(inp, "%d", &r);

        fprintf(outp, "%d ", arr[r]-arr[l-1]);
    }
}
