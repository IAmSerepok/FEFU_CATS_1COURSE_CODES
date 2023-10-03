#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    char a[20];
    fscanf(inp, "%s", &a);

    char s = '=';

    int j = -1;

    for (int i = 0; i < strlen(a); i++)
    {
        j += 1;
        char c = a[i];

        if (c == '&')
        {
            if (a[i + 1] == 'l')
            {
                c = '<';
            }
            else
            {
                c = '>';
            }
            i += 3;
        }

        if (c != s && c != '=')
        {
            if (s != '=')
            {
                for(int t = 0; t < 5 - j; t++){
                    fprintf(outp, "?");
                    printf("?");
                }
                break;
            }
            else
            {
                s = c;
            }
        }

        if (s == '=') c = '*';
        else if (s == '>') c = '-';
        else if (s == '<') c = '+';

        fprintf(outp, "%c", c);
        printf("%c", c);
    }
}
