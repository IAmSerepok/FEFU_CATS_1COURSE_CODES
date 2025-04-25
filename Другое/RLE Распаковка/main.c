#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    FILE * inp = fopen("input.txt","w");
    FILE * outp = fopen("output.txt","r");
    unsigned char c;

    while(feof(outp) == 0){

        fscanf(outp, "%d %c", &num, &c);

        if(feof(outp) == 0){

                for(int i = 0; i < num; i++){

                    printf("%c", c);
                    fprintf(inp, "%c", c);
                }
        }
    }
}
