#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    double res, x, a;

    scanf("%d", &n);
    scanf("%lf", &x);
    scanf("%lf", &res);

    for(int i = 0; i < n; i++){
        scanf("%lf", &a);
        res=res * x + a;
    }

    printf("%g",res);
}
