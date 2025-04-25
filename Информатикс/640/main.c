#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int d0,m0,d,m,g,g0,n0,n,res,i=0,a,a0,g1,g10,m1,m10;
    scanf("%d %d %d %d %d",&d0,&m0,&d,&m,&g);
    a = floor((14-m)/12);
    g1 = g+4800-a;
    m1 = m+12*a-3;
    n= d + floor((153*m1+2)/5) + 365*g1 + floor(g1/4) - floor(g1/100) + floor(g1/400) - 32045;
    if(d0==29 && m0==2)
        {
        if(((m0>m)|((m0==m)&&(d0>=d))))
        {
            if((g % 4 == 0 & g % 100!=0) |  (g % 400 == 0))
            {g0=g;}
            else{
                g++;
            while(i==0)
            {
                if((g % 4 == 0 & g % 100!=0) |  (g % 400 == 0))
                {
                    i=1;
                    g0=g;
                }
                g++;
            }
            }
        }else{
            g++;
            while(i==0)
            {
                if((g % 4 == 0 & g % 100!=0) |  (g % 400 == 0))
                {
                    i=1;
                    g0=g;
                }
                g++;
            }
        }
        }else{
        if((m0>m)|((m0==m)&(d0>=d)))
           {
                g0=g;
           }else g0=g+1;
    }
    a0 = floor((14-m0)/12);
    g10 = g0+4800-a0;
    m10 = m0+12*a0-3;
    n0= d0 + floor((153*m10+2)/5) + 365*g10 + floor(g10/4) - floor(g10/100) + floor(g10/400) - 32045;
    res=n0-n;
    printf("%d",res);
}
