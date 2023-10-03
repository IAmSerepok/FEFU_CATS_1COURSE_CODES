#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE * inp=fopen("input.txt", "r");
    FILE * outp=fopen("output.txt", "w");

    int x1,y1,x2,y2,x,y;
    float x0,y0,CenD,AngD1,AngD2,AngD3,AngD4;

    fscanf(inp,"%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x,&y);

    x0=(x1+x2)/2;
    y0=(y1+y2)/2;
    CenD=((x-x0)*(x-x0)+(y-y0)*(y-y0));
    AngD1=((x-x1)*(x-x1)+(y-y1)*(y-y1));
    AngD2=((x-x2)*(x-x2)+(y-y2)*(y-y2));
    AngD3=((x-x1)*(x-x1)+(y-y2)*(y-y2));
    AngD4=((x-x2)*(x-x2)+(y-y1)*(y-y1));

    if(CenD <= AngD1 && CenD <= AngD2 && CenD <= AngD3 && CenD <= AngD4)
        fprintf(outp,"CENTER");
    else
        fprintf(outp,"CORNER");
}
