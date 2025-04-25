#include <stdio.h>
#include <stdlib.h>

long long merge(float mass[],  float subMass[], int left, int mid, int right) //slianie
{
    int i, j, k;
    long long res = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if ((mass[i] >= mass[j]))
        {
            subMass[k++] = mass[i++];
        }
        else
        {
            subMass[k++] = mass[j++];
            res = res + (mid - i);
        }
    }
    while (i <= mid - 1) {
        subMass[k++] = mass[i++];
    }
    while (j <= right) {
        subMass[k++] = mass[j++];
    }
    for (i = left; i <= right; i++){

        mass[i] = subMass[i];
    }

    return res;
}

long long _mergeSort(float mass[], float subMass[], int left, int right)
{
    int mid;
    long long res = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        res += _mergeSort(mass,subMass, left, mid);
        res += _mergeSort(mass, subMass, mid + 1, right);

        res += merge(mass, subMass, left, mid + 1, right);
    }
    return res;
}

long long mergeSort(float mass[], int n)
{
    float subMass[n];
    return _mergeSort(mass, subMass,  0, n - 1);
}

int main()
{
    FILE *inp = fopen("input.txt", "r"), *outp = fopen("output.txt", "w");

    int n;

    fscanf(inp, "%d", &n);

    float arr[n+1];
    char name[255];

    for(int i = 0; i < n; i++)
        fscanf(inp, "%f %s", &arr[i], &name);

    fprintf(outp, "%lld", mergeSort(arr, n));
}
