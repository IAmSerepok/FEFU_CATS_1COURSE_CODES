#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");
    int sum = 0;
    char c;

    for(;;){

        fscanf(inp, "%c", &c);

        if(c == '1' || c == '0'){

            if(c ==  '1')sum++;
            printf("%c", c);
        }

        if(c == 'e' || c == 'o') break;
    }
    sum %= 2;

    if (c == 'e'){

        if (sum == 1) printf("1");
        else printf("0");
    }

    else{

        if (sum == 0) printf("1");
        else printf("0");
    }
}
