#include <stdio.h>
#include <math.h>

int main() {

    FILE * inp  = fopen("input.txt", "r");

    int sum = 0, n, m, num2 = 0, num1 = 0, lenn = 0, lenm = 0;
    int arr1[2][10000] = {}, arr2[10000] = {};
    char m_prev = -1, c;

    fscanf(inp, "%d %d\n", &n, &m);

    for(int i = 0; i < n; i++){

        fscanf(inp, "%c", &c);

        if(c == '0'){

            num1++;
        }
            else{

            if(num1 > 0){

                arr1[0][lenn] = (-1)*num1;
                lenn++;
            }

            arr1[0][lenn] = 1;
            lenn++;
            num1 = 0;
        }
    }

    if(c == '0'){
        arr1[0][lenn] = (-1)*num1;
        lenn++;
    }

    fscanf(inp, "\n");

    for(int j = 0; j < m; j++) {

        fscanf(inp, "%c", &c);

        if(c == m_prev)
            num2++;

        else{
            if(num2) {
                if(m_prev == 'b')
                    arr2[lenm] = num2;
                else
                    arr2[lenm] = (-1)*num2;
                lenm++;
            }
            num2 = 1;
            m_prev = c;
        }
    }

    fclose(inp);

    if(m_prev == 'b')
        arr2[lenm] = num2;
    else
        arr2[lenm] = (-1)*num2;
    lenm++;

    if(arr2[0] < 0)
        for(int i = 0; sum + abs(arr1[0][i]) <= (-1)*arr2[0] && i < lenn; i++) {
            sum = sum + abs(arr1[0][i]);
            arr1[1][i] = 1;
        }

    else
        for(int i = 0; ++sum <= arr2[0] && i < lenn && arr1[0][i] == 1; arr1[1][i++] = 1);

    for(int j = 1; j < lenm; j++){

        for(int i = lenn - 1; i >= 0; i--){

            if(arr1[1][i] != 0){
                sum = 0;
                if(arr2[j] < 0)
                    for(int k = i + 1; (sum + abs(arr1[0][k]) <= (-1)*arr2[j]) && k < lenn; k++){

                        sum += abs(arr1[0][k]);
                        arr1[1][k] = 1;
                    }
                else
                    for (int k = i + 1; ++sum <= arr2[j] && arr1[0][k] == 1; arr1[1][k] = 1, k++);
                        arr1[1][i] = 0;
            }
        }
    }

    FILE * outp = fopen("output.txt", "w");

    if(arr1[1][lenn - 1])
        fprintf(outp, "Y");
    else
        fprintf(outp, "N");

    fclose(inp);
}

