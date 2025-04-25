#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BASE = 10;

int max(int x, int y){
    if (x>=y) return x;
    else return y;
}

int main()
{
    FILE * inp=fopen("input.txt","r");
    FILE * outp=fopen("output.txt","w");
    char num1[10001] = {}, num2[10001] = {}; int res[10001] = {}, j1 = 0, j2 = 0;
    fscanf(inp, "%s%s", &num1, &num2);

    for(int i = strlen(num1)-1; i >= 0 ; i--){
        int a = num1[i] - 48;
        res[j1] += a;
        j1++;
    }

    for(int i = strlen(num2)-1; i >= 0 ; i--){
        int a = num2[i] - 48;
        res[j2] -= a;
        j2++;
    }

    j1 = max(j1, j2);

    for(int i = 0; i < j1; i++){
        if(res[i] < 0){
            res[i] += BASE;
            res[i+1]--;
        }
    }

    for(int i = j1-1; i >= 0; i--){
        fprintf(outp, "%d", res[i]);
    }
}
