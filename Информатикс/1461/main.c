#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sm = 0, cen, buff1, buff2, res = 0;
    scanf("%d", &n);
    int arr[n][2];
    scanf("%d", &buff1);
    arr[0][0] = buff1;

    for(int i = 0; i < n; i++)
        arr[i][1] = 1;

    int i = 1;
    for(int j = 1; j < n; j++){
        scanf("%d", &buff2);
        if(buff1 == buff2)
            arr[i-1][1]++;
        else{
            arr[i][0] = buff2;
            i++;
        }
        buff1 = buff2;
    }

    for(int g = 0; g < i; g++){

        if(arr[g][1] >= 3){
            cen = g;
            res += arr[g][1];
        }
    }

    if(cen > i - cen - 1)
        sm = i - cen - 1;
    else
        sm = cen;

    for(int as = 1; as <= sm; as++){

        if(arr[cen-as][0] == arr[cen+as][0] && arr[cen+as][1] + arr[cen-as][1]>=3)
            res += arr[cen-as][1] + arr[cen+as][1];
        else
            break;
    }


    printf("%d",res);
}
