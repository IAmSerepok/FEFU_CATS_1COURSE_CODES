#include <stdio.h>
#include <math.h>

int main(){
    int N, i, suml = 0, sumr = 0, j, pos = 0, msum = -1, L = -1,M,R;

    scanf("%d", &N);

    //считывание
    int arr[N];
    for(i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < N; i++){
        suml = 0;
        sumr = arr[i];
        pos = i + 1;
        for(j = i; j < N; j++){
            sumr -= arr [j];
            suml += arr[j];
            while((pos< N) && (sumr < suml)){
                sumr += arr[pos];
                pos ++;
            }
            if(suml == sumr){
                if(msum < suml){
                    msum = suml;
                    L = i;
                    M = j;
                    R = pos;
                }

            }
        }
    }
    if (L >= 0){
        printf("%d %d %d", L + 1, M + 1, R );
    }
    else{
        printf("%d", -1 );
    }
}
