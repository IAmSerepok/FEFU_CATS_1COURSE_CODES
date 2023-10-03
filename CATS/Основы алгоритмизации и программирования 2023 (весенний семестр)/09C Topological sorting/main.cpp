#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ifstream fin("input.txt");

    int n, m;
    fin >> n >> m;

    queue<int> que;
    vector<int> otv;
    vector<vector<int>> smej(n + 1);
    vector<int> mass(n + 1, 0);

    for (int i = 0; i < m; i++) {

        int a, b;
        fin >> a >> b;
        smej[a].emplace_back(b);
        mass[b]++;
    }

    for (int i = 1; i <= n; i++) if (mass[i] == 0) que.push(i);

    while (que.empty() != 1) {

        int v = que.front();
        otv.emplace_back(v);
        que.pop();

        for (int u : smej[v]) {
            mass[u]--;
            if (mass[u] == 0) que.push(u);
        }
    }
    ofstream fout("output.txt");

    if (otv.size() != n) fout << -1;

    else{

        for (int v : otv)
            fout << v << " ";

        fout << '\n';
    }
    fout.close();
    fin.close();
}