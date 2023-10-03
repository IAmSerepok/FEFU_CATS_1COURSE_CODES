#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

int N;
bool arr[101][101];
bool visited[101];

void dfs(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < N; i++) {
        if (arr[v][i]) {

            if (i == parent) continue;

            if (visited[i]) {
                cout << "NO";
                exit(0);
            }
            dfs(i, v);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, -1);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}