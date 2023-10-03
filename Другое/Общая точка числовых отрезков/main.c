#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp;
    FILE * outp;
    inp=fopen("input.txt","r");
    outp=fopen("output.txt","w");

    int t;
    fscanf(inp, "%d", &t);

    for(int ti=0;ti<t;ti++){

        int n,i=0;
        double a1,a2,b1,b2,resa,resb;
        fscanf(inp, "%d", &n);
        fscanf(inp, "%lf", &a1);
        fscanf(inp, "%lf", &b1);

        for(int ni=1;ni<n;ni++){

            fscanf(inp, "%lf", &a2);
            fscanf(inp, "%lf", &b2);

            if(a1>=a2)
                resa=a1;
            else
                resa=a2;
            if(b1<=b2)
                resb=b1;
            else
                resb=b2;

            a1=resa;
            b1=resb;

            if(resb<resa && i==0){
            printf("NO\n");
            i++;
            }
        }
        if(i==0)
            printf("YES %lf\n", resa);
    }
}
