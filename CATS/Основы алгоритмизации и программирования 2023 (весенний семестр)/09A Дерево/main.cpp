#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

int N, M;
bool graph[10000][10000];
bool visited[10000];

void dfs(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < N; i++) {
        if (graph[v][i]) {

            if (i == parent) continue;

            if (visited[i]) {
                fout << "NO";
                exit(0);
            }
            dfs(i, v);
        }
    }
}

int main() {
    fin >> N >> M;

    if (!(M == N - 1)) {
        fout << "NO";
        return 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = 1;
    }

    dfs(0, -1);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            fout << "NO";
            return 0;
        }
    }

    fout << "YES";
}