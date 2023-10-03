#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(float arr[], int a[], int left, int right)
{
    int mid;
    if (left < right){

        mid = (left + right) / 2;
        sort(arr, a, left, mid);
        sort(arr, a, mid + 1, right);

        float hArr[right];
        int ha[right];
        int i, j, k;
        i = left;
        k = left;
        j = mid + 1;

        while (i <= mid && j <= right){

            if (arr[i] >= arr[j]){

                hArr[k] = arr[i];
                ha[k] = a[i];
                k++;
                i++;
            }
            else{

                hArr[k] = arr[j];
                ha[k] = a[j];

                k++;
                j++;
            }
        }

        while (i <= mid){

            ha[k] = a[i];
            hArr[k] = arr[i];

            k++;
            i++;
        }

        while (j <= right){

            hArr[k] = arr[j];
            ha[k] = a[j];
            k++;
            j++;
        }

        for (i = left; i < k; i++){

            a[i] = ha[i];
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

    float len[n];
    char names[n][256];
    int num[n];

    for (int i = 0; i < n; i++){

        num[i] = i;
        fscanf(inp, "%f %s", &len[i], &names[i]);
    }

    sort(len, num, 0, n - 1);

    for (int i = 0; i < n; i++){

        fprintf(outp, "%s\n", names[num[i]]);
    }

}
