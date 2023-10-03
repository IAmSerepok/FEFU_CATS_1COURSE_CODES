#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int N,prom,max=-2147483648;
    scanf("%d",&N);
    int Mass[N+1];

    for(int i=0;i<N;i++){
        scanf("%d",&prom);
        Mass[i]=prom;
    }

    for(int i=0;i<N;i++)  if(max<Mass[i])  max=Mass[i];

    printf("%d",max);
}
