#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int x, int y){
    if (x>=y) return x;
    else return y;
}

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    int num;
    int ChetSumm = 0;
    int NechSumm = 0;
    fscanf(inp, "%d", & num);
    printf("%d ",  num);
    int nech[101] = {};
    int chet[101] = {};

    for (int i = 0; i < num; i++)
    {
        int buff;
        fscanf(inp, "%d", & buff);
        nech[i] = buff;
        chet[i] = buff;
    }
    if (num > 1)
    {
        if (num == 2)
        {
            int a1 = nech[0], a2 = nech[1];
            if (a1 == a2)
            {
                a1 += 1;
            }
            fprintf(outp, "%d %d", a1 ,a2);
            printf("%d %d", a1 ,a2);
        }
        else
        {
            for (int i = 2; i < num; i++)
            {
                int a3 = nech[i];

                int a11 = nech[i - 2], a12 = nech[i - 1];
                int a21 = chet[i - 2], a22 = chet[i - 1];
                if (((i + 1) % 2) != 0) //chetnost indexa
                {
                    if (a11 <= a12)
                    {
                        int delt = 1 + a12 - a11;
                        nech[i - 2] += delt;
                        NechSumm += delt;
                    }
                    if (a3 <= a12)
                    {
                        int delt = 1 + a12 - a3;
                        nech[i] += delt;
                        NechSumm += delt;
                    }

                    if (a22 <= max(a21, a3))
                    {
                        int delt = 1 + max(a21, a3) - a22;
                        chet[i - 1] += delt;
                        ChetSumm += delt;
                    }
                }
                else
                {
                    if (a12 <= max(a11, a3))
                    {
                        int delt = 1 + max(a11, a3) - a12;
                        nech[i - 1] += delt;
                        NechSumm += delt;
                    }

                    if (a21 <= a22)
                    {
                        int delt = 1 + a22 - a21;
                        chet[i - 2] += delt;
                        ChetSumm += delt;
                    }
                    if (a3 <= a22)
                    {
                        int delt = 1 + a22 - a3;
                        chet[i] += delt;
                        ChetSumm += delt;
                    }
                }
            }
            if (NechSumm < ChetSumm)
            {
                for (int i = 0; i < num; i++)
                {
                    fprintf(outp, "%d ", nech[i]);
                    printf("%d ", nech[i]);
                }
            }
            else
            {
                for (int i = 0; i < num; i++)
                {
                    fprintf(outp, "%d ", chet[i]);
                    printf("%d ", chet[i]);
                }
            }
        }
    }
    else
    {
        int buff;
        fscanf(inp, "%d", & buff);
        fprintf(outp, "%d", buff);
        printf("%d", buff);
    }
    printf("\n");
}
