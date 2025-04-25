#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n,k=2,j;
    scanf("%d",&n);
    bool arr[n+1];
    for(int i=2;i<=n;i++)
        arr[i]=true;
    while (k*k <= n) {
        if (arr[k]){
            j = k*k;
        while (j <= n) {
        arr[j] = false;
        j += k;
        }
    }
    k++;
    }
    for (int i=2;i<=n;i++){
    if (arr[i])
    printf("%d ",i);
    }
}
