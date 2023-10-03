#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE * inp=fopen("input.txt", "r");
    FILE * outp=fopen("output.txt", "w");

    int n;
    fscanf(inp, "%d", &n);
    int k = pow(2, n);
    int arr[n];

    for(int i = 0; i < k; i++){
        int num = i;

        for(int j = n-1; j >=0; j--){
            arr[j] = num % 2;
            num /= 2;
        }
        for(int m = 0; m < n; m++){
            fprintf(outp,"%d",arr[m]);
        }
        fprintf(outp, "\n");
    }
}
