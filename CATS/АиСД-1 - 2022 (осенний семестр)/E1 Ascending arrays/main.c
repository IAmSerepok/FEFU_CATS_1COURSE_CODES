#include <stdio.h>
#include <stdlib.h>

int func(int arr[], int left, int right, int val, int n){

	for (int i = 0; i <= n; i++){

		int mid = (left + right) / 2;

        if  (val == arr[mid]) return 1;

        if (val > arr[mid]) left = mid + 1;

		else right = mid - 1;

		if (right < left) return 0;
	}
}

int main() {

    FILE * inp = fopen("input.txt", "r");
    FILE * outp = fopen("output.txt", "w");

    int l1, l2, l3, res = 0;

    fscanf(inp, "%d%d%d", &l1, &l2, &l3);

    int a[l1+1], b[l2+1], c[l3+1];

    for (int i = 0; i < l1; i++)
        fscanf(inp, "%d", &a[i]);

    for (int i = 0; i < l2; i++)
        fscanf(inp, "%d", &b[i]);

    for (int i = 0; i < l3; i++)
        fscanf(inp, "%d", &c[i]);

    for (int i = 0; i < l1; i++)
        if (func(b, 0, l2-1, a[i], l2) == 1)
            if (func(c, 0, l3-1, a[i], l3) == 1)
                res++;

    fprintf(outp, "%d", res);

    fclose(inp);
    fclose(outp);
}
