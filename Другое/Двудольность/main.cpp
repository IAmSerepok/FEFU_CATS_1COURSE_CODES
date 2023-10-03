#include <iostream>
#include <vector>

using namespace std;

#define vec vector

int DFS(int n, int k, vec<vec<int>> arr, int color[]){

    static int fl = 1;

    for(int i = 0; i < n; i++){

        if(arr[k][i] != 0 && color[i] == -1){

            color[i] = (color[k]+1)%2;
            DFS(n, i, arr, color);
        }
        if(arr[k][i] != 0 && color[i] != -1 && color[i] == color[k]){

            fl = 0;
        }
    }
    if (fl == 1) return 0;
    else return -1;
}

int main() {

    int n, k;
    cin >> n;
    vec<vec<int>> arr(n, vec<int>(n));
    int color[n];
    for (int i = 0; i < n; i++) color[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int fl = 1, f = 1;
    while (fl == 1){
        fl = 0;
        for (int i = 0; i < n; i++) {

            if(color[i] == -1) {

                fl = 1;
                color[i] = 0;
                if(DFS(n, i, arr, color) == -1){

                    cout << "NO";
                    fl = 0;
                    f = 0;
                }
                break;
            }
        }
    }
    if(f==1){
        cout << "YES";
    }
}
