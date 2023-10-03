#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    int x1, y1, x2, y2, x, y, flag = 0;
    fscanf(inp, "%d %d %d %d", &x1, &y1, &x2, &y2);

    if (((x1 + y1) % 2 != (x2 + y2) % 2) || (abs(x2 - x1) == abs(y2 - y1) && abs(x1 - x2) == 1)){
        fprintf(outp, "%d", 0);
        flag++;
    }
    if(flag == 0){
        if(abs(x1 - x2) == abs(y1 - y2)){

                   if(x2 > x1 && y2 > y1){
                    x = x1 + 1;
                    y = y1 + 1;
                   }
                   if(x1 > x2 && y1 > y2){
                    x = x2 + 1;
                    y = y2 + 1;
                   }
                   if(y2 > y1 && x1 > x2){
                    y = y1 + 1;
                    x = x1 - 1;
                   }
                   if(y2 < y1 && x1 < x2){
                    x = x2 - 1;
                    y = y2 + 1;
                   }
        }
        else{

            for(int i = 1; i <= 8; i++)
                for(int j = 1; j <=8; j++){
                    if((abs(x1 - i) == abs(y1 - j)) && (abs(x2 - i) == abs(y2 - j))){

                        x = i;
                        y = j;
                }
            }
    }

    fprintf(outp, "%d %d", x, y);
    return 0;
    }
}

