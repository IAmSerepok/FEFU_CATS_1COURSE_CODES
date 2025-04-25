#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[10001];
    int res = 0;
    scanf("%s", &arr);
    int len = strlen(arr);
    len++;

    char op = '+';

    for(int i = 0; i < len; i++){
        int num = 0;
        for(;(arr[i] == '0' || arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9');i++){
            int n = arr[i] - 48;
            num = num * 10 + n;
        }
        if(op == '+')
            res+=num;
        else
            res-=num;
        op = arr[i];
    }
    printf("%d", res);
}
