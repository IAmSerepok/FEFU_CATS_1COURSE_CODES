#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double * res = (double*)malloc(sizeof (double));

    FILE * inp = fopen("input.txt", "r");
    FILE * outp = fopen("output.txt", "w");

    int k;
    double prom, n;

    fscanf(inp, "%lf", &n);
    fscanf(inp, "%d", &k);

    fclose(inp);

    int N = floor(sqrt(n)), len, flag = 0;

    for(;N > 0;N --){

        res[0] = N;

        prom = n - pow(N, 2);

        if(prom == 0){

            flag = 1;
            k = 1;
        }

        else{

            for (int i = 1; i < k; i++){

                len = floor(sqrt(prom));
                prom -= pow(len, 2);

                res = (double *) realloc(res, sizeof(double));

                res[i] = len;

                if (prom == 0){

                    k = i + 1;
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) break;
    }

    if (flag == 0) fprintf(outp, "NO\n");

    else{

        fprintf(outp, "YES\n");

        for (int i = k - 1; i >= 0; i--){

            fprintf(outp, "%.0lf ", res[i]);
        }
    }
}
