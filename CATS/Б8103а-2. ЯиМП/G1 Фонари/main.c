#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    int arr[102]={};

    int n, max = 0;
    fscanf(inp, "%d", &n);

    for(int i = 0; i < n; i++){

        int x, y;
        fscanf(inp, "%d %d", &x, &y);

        for(int j = x - y + 1; j <= x + y; j++)
            if(j > 0 && j <101)
                arr[j]++;
    }

    for(int i = 1; i < 101; i++){

        if(arr[i] > max)
            max = arr[i];
    }

    fprintf(outp, "%d", max);
}
