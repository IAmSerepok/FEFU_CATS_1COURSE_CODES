#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,buff;
    scanf("%d",&n);
    int arr[n+1];

    for(int i=1;i<=n;i++){
        scanf("%d",&buff);
        arr[i]=buff;
    }

    for(int j=1;j<=n/2;j++){
        buff=arr[j];
        arr[j]=arr[n+1-j];
        arr[n+1-j]=buff;
    }

    for(int k=1;k<=n;k++)
        printf("%d ",arr[k]);
}
