#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    if((n % 4 == 0 & n % 100!=0) |  (n % 400 == 0)) printf("YES");
    else printf("NO");
}
