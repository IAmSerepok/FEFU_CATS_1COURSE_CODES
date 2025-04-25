#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int code;
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");
    unsigned char c, buff;
    unsigned char num = 1;
    fscanf(inp, "%c", &c);

    while(feof(inp) == 0){

        fscanf(inp, "%c", &buff);

        if(feof(inp) == 0){

            if(buff != c || num == 127){

                printf("%d%c ", num, c);
                fprintf(outp, "%d%c", num, c);
                c = buff;
                num = 1;
            }
            else{
                num++;
            }
        }
    }
    printf("%d%c", num, c);
    fprintf(outp, "%d%c", num, c);
}
