#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");
    int n = 0, a, arr[11], A = 0, B;
    fscanf(inp, "%d", &a);
    for(int i = 0; a > 0; i++){
        arr[i] = a % 10;
        a /= 10;
        n++;
    }

    for(int i = 0 ; i < n - 1; i++) {

       for(int j = 0 ; j < n - i - 1 ; j++) {

           if(arr[j] > arr[j+1]) {
              int tmp = arr[j];
              arr[j] = arr[j+1] ;
              arr[j+1] = tmp;
           }
        }
    }

    B = arr[0];
    n--;

    for(int i = n; i >0; i--){

        A += arr[i];
        A *= 10;
    }

    A /= 10;

    fprintf(outp, "%d %d", A, B);

}
