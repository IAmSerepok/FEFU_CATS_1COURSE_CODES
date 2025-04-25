#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int arr[], int left, int right)
{
    int mid;
    if (left < right){

        mid = (left + right) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        int hArr[right - left + 1];

        int i, j, k;
        i = left;
        k = left;
        j = mid + 1;

        while (i <= mid && j <= right){

            if (arr[i] >= arr[j]){

                hArr[k] = arr[i];

                k++;
                i++;
            }
            else{

                hArr[k] = arr[j];

                k++;
                j++;
            }
        }

        while (i <= mid){

            hArr[k] = arr[i];

            k++;
            i++;
        }

        while (j <= right){

            hArr[k] = arr[j];

            k++;
            j++;
        }

        for (i = left; i < k; i++){

            arr[i] = hArr[i];
        }
    }
}

int main()
{
    FILE * inp = fopen("input.txt","r");
    FILE * outp = fopen("output.txt","w");

    int n;
    fscanf(inp, "%d", &n);

    int len[n+1];

    for (int i = 0; i < n; i++)
        fscanf(inp, "%d", &len[i]);

    sort(len, 0, n - 1);

    for (int i = n-1; i >= 0; i--){

        fprintf(outp, "%d ", len[i]);
    }
}
