#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vec vector

void DFS(int n, int k, vec<vec<int>> arr, int color[]){

    color[k] = 1;

    for(int i = 0; i < n; i++){

        if(arr[k][i] != 0 && color[i] == 0){

            DFS(n, i, arr, color);
        }
    }
}

void BFS(int n, int k, vec<vec<int>> arr, int color[]){

    queue<int> que;
    color[k] = -1;
    que.push(k);

    for(;!que.empty();){

        int a = que.front();
        color[a] = 1;
        que.pop();
        for(int i = 0; i < n; i++){

            if(arr[a][i] != 0 && color[i] == 0){

                color[i] = -1;
                que.push(i);
            }
        }
    }
}



int main() {

    int n, k; cin >> n >> k; vec<vec<int>> arr(n, vec<int>(n)); int color[n];
    for(int i = 0; i < n; i++) color[i]=0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    BFS(n, k-1, arr, color);

    int fl = 0;
    for(int i = 0; i < n; i++){
        fl += color[i];
    }

    cout << fl;
}
