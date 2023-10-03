#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    FILE * inp = fopen("input.txt", "r");

    long long r, n, res[100001] = {};

    fscanf(inp, "%lld %lld", &n, &r);

    fclose(inp);

    if (r - n % 2 - n / 2 <= 0){

        res[r - 1] = pow((n - (r - 1) * 2), 2);

        int buff = 0;

        if(r > 2)
            buff = r;

        for (long long i = buff; i <= n - r; i++){

            res[i] = res[r - 1] + r - i - 1;
        }

    }
    else{

        res[r - 1] = pow((n - 2*r + 1), 2) + 1;

        for (long long i = r - 2; i >= n - r; i--)
            res[i] = res[r - 1] - r + i + 1;
    }
    for (long long i = 0; i < n / 2 + n % 2; i++){

        if (res[i] == 0)
            res[i] = pow((n - i * 2), 2) - 4*n + 7*i + 3 + r;
        else
            break;
    }
    for (long long i = 0; i < n / 2 + n % 2; i++){

        if (res[n - 1 - i] == 0)
            res[n - 1 - i] = pow((n - i * 2), 2) - n + 3*i - r + 2;
        else
            break;
    }

    FILE * outp = fopen("output.txt", "w");

    for (long long i = 0; i < n; i++)
        fprintf(outp, "%lld ", res[i]);

    fclose(outp);
}
