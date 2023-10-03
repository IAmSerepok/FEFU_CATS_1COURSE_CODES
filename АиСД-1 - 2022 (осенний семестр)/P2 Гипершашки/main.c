#include <stdio.h>

typedef struct str {
    long long a;
    int b;
} str;

int buff[100000], arr[100000];
str num1[100000], num2[100000];

long long serch(struct str Arr[], int n, long long int Key) {

    long long l = 0;
    long long r = n - 1;
    long long m = (r + l) / 2;

    for(;l <= r; m = (l + r) / 2) {

        if (Arr[m].a == Key) return m + 1;

        else if (Arr[m].a > Key)
            r = m - 1;
        else
            l = m + 1;
    }
    if (Arr[m].a <= Key) m++;

    return m;
}

void mergesort(int mas[], int l, int r) {

    if (l == r) return;

    int m = (l + r) / 2;

    mergesort(mas, l, m);
    mergesort(mas, m + 1, r);

    int i = l;
    int j = m + 1;

    for (int k = 0; k <= r - l; k++) {

        if (((i <= m) && (mas[i] <= mas[j])) || (j > r))
            arr[k] = mas[i++];
        else
            arr[k] = mas[j++];
    }

    for (int k = 0; k <= r - l; k++)
        mas[l + k] = arr[k];
}

int main(){

    FILE * inp = fopen("input.txt", "r");

    int n, k, size = 1;
    long long res = 0;

    fscanf(inp, "%d", &n);
    fscanf(inp, "%d", &k);

    for (int i = 0; i < n; i++)
        fscanf(inp, "%d", &buff[i]);

    fclose(inp);

    mergesort(buff, 0, n - 1);

    num1[0].a = buff[0];
    num1[0].b = 1;

    for (int i = 1; i < n; i++) {
        if (buff[i] == num1[size - 1].a) {
            num1[size - 1].b += 1;
        }
        else {
            size++;
            num1[size - 1].a = buff[i];
            num1[size - 1].b = 1;
        }
    }

    int size2 = 0;
    for (int i = 0; i < size; i++) {
        if (num1[i].b > 2) {
            res++;
        }
        if (num1[i].b > 1) {
            num2[size2] = num1[i];
            size2++;
        }
    }

    for (int i = 0; i < size; i++) {

        long long int top = serch(num2, size2, num1[i].a * k);
        long long int down = serch(num2, size2, num1[i].a);
        res += 3 * (top - down);
    }

    for (int i = 0; i < size2; i++) {

        long long int top = serch(num1, size, num2[i].a * k);
        long long int down = serch(num1, size, num2[i].a);
        res += 3 * (top - down);
    }

    for (int i = 0; i < size; i++) {

        long long int top = serch(num1, size, num1[i].a * k);
        long long int down = serch(num1, size, num1[i].a);
        long long int len = top - down;
        res += 6 * len * (len - 1) / 2;
    }

    FILE * outp = fopen("output.txt", "w");

    fprintf(outp, "%lld", res);

    fclose(outp);
}
