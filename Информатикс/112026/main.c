#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[300001], str2[300001];
    scanf("%s %s", &str1, &str2);
    int len = strlen(str1), res = 0;

    for(int i = 0; i < len; i++)
        if(str1[i] != str2[i])
            res++;
    printf("%d", res);
}
