#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[10];
    int n, k = 0, set[100002];
    scanf("%d", &n);

    for(; n > 0; n--){

        scanf("%s", &str);

        if(str[0] == 'A' && str[1] == 'D' && str[2] == 'D'){
            int num, i = 0;
            scanf("%d", &num);
            for(int pl = 0; pl < k; pl++)
                if(set[pl] == num){
                    i++;
                    break;
                }
            if(i == 0){
                    set[k] = num;
                    k++;
            }
        }

        if(str[0] == 'C' && str[1] == 'O' && str[2] == 'U' && str[3] == 'N' && str[4] == 'T')
            printf("%d\n", k);

        if(str[0] == 'P' && str[1] == 'R' && str[2] == 'E' && str[3] == 'S' && str[4] == 'E' && str[5] == 'N' && str[6] == 'T'){

            int num, i = 0;
            scanf("%d", &num);
            for(int kl = 0; kl < k; kl++)
                if(set[kl] == num){
                    i++;
                    break;
                }
            if(i == 0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}
