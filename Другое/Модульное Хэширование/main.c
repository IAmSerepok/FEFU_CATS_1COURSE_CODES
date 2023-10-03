#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");
    int m, codesumm = 0;
    int buff;
    fscanf(inp, "%d", &m);
    fscanf(inp, "%c", &buff);

    while(feof(inp) == 0){

        fscanf(inp, "%c", &buff);

        if(feof(inp) == 0){

            while(buff != 32 && feof(inp) == 0){
                if(feof(inp) == 0){
                    codesumm += buff;
                    fscanf(inp, "%c", &buff);
                }
            }
        }
        codesumm %= m;
        fprintf(outp, "%d\n", codesumm);
        printf("%d\n", codesumm);
        codesumm = 0;
    }
}
