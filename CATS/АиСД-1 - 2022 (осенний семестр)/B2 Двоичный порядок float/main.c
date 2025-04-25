#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float buff;
    union a{
        float f;
        int num;
    } id;

    scanf("%f", &buff);
    id.f = buff;

    int res =(((id.num)>>23)&(255)) - 127;



    if(res < -126)
        res = -126;

    if(res > 128)
        res = 128;

    printf("%d", res);
}
