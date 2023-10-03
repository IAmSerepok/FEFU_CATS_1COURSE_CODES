#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inp = fopen("input.txt", "r"), *outp = fopen("output.txt", "w");

    int arr[4][3]={{1, 2}, {1, 2}, {-1, 2}};

    int sost = 0; char c;

    fscanf(inp, "%c", &c);

    while(sost != -1 && feof(inp) == 0){

        if(c > 96 && c < 123){printf("1");

            sost = arr[sost][0];
        }

        else if(c > 64 && c < 91){printf("2");

            sost = arr[sost][1];
        }

        fscanf(inp, "%c", &c);
    }

    if(sost == -1) fprintf(outp, "NO");
    else fprintf(outp, "YES");
}
