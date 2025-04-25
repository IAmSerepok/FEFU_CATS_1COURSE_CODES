#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    int n,i=0;
    double aX1, aX2, bX1, bX2, aY1, aY2, bY1, bY2, x, y, l, resXa, resYa, resXb, resYb;
    fscanf(inp, "%d", &n);
    fscanf(inp, "%lf", &x);
    fscanf(inp, "%lf", &y);
    fscanf(inp, "%lf", &l);

    aX1 = x - l / 2;

    bX1 = x + l / 2;
    aY1 = y - l / 2;
    bY1 = y + l / 2;

        for(int ni=1;ni<n;ni++){

            fscanf(inp, "%lf", &x);
            fscanf(inp, "%lf", &y);
            fscanf(inp, "%lf", &l);
            printf("%lf %lf %lf \n", x, y, l);

            aX2 = x - l / 2;
            bX2 = x + l / 2;
            aY2 = y - l / 2;
            bY2 = y + l / 2;

            if(aX1>=aX2)
                resXa=aX1;
            else
                resXa=aX2;
            if(bX1<=bX2)
                resXb=bX1;
            else
                resXb=bX2;
            if(aY1>=aY2)
                resYa=aY1;
            else
                resYa=aY2;
            if(bY1<=bY2)
                resYb=bY1;
            else
                resYb=bY2;

            aX1=resXa;
            bX1=resXb;
            aY1=resYa;
            bY1=resYb;

            if((resXb<resXa || resYb<resYa) && i==0){
            printf("NO\n");
            i++;
            }
        }
        if(i==0)
            printf("YES %lf %lf\n", resXa, resYa);

}
