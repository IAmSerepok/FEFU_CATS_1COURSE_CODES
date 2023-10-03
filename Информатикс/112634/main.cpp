#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int mass[n][n];

    int arr[n+1]; arr[0]=1; for(int i = 1; i < n; i++) arr[i] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            int a;
            cin >> a;
            mass[i][j] = a;
        }
    }
    int nums = 1;

    while(1){

        if(nums < 1) break;

        int i = 0;
        while(arr[i] != 1) i++;

        arr[i] = 2;
        nums--;

        for(int j = 0; j < n; j++){

            if(mass[i][j] != 0 && arr[j] == 0){

                arr[j] = 1;
                nums++;
            }
        }
    }

    int fl = 1;
    for(int y = 0; y < n; y++) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                fl = 0;
                break;
            }
        }
    }

    if(fl == 1) cout << "YES";
    else cout << "NO";
}