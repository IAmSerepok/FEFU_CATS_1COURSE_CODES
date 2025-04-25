#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[9][6]={{-1,0,0,0,0,0},{-1,2,3,-1,-1,-1},{-1,-1,3,-1,-1,-1},{-1,-1,3,4,5,-10},{-1,-1,6,-1,-1,-1},{-1,7,8,-1,-1,-1},{-1,-1,6,-1,5,-10},{-1,-1,8,-1,-1,-1},{-1,-1,8,-1,-1,-10}};

    int sost = 1,simv;
    char str[201];
    scanf("%s", &str);
    int len = strlen(str);

    for(int i = 0; i <= len && sost != -1; i++){
        int t = str[i];
        if(t == 0)
            simv = 5;
        else if(str[i] == 'e' || str[i] == 'E')
            simv = 4;
        else if(str[i] == '.')
            simv = 3;
        else if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
            simv = 2;
        else if(str[i] == '+' || str[i] == '-')
            simv = 1;
        else
            simv = 0;
        sost = arr[sost][simv];
    }
    if(sost == -1)
        printf("NO");
    else
        printf("YES");
}
