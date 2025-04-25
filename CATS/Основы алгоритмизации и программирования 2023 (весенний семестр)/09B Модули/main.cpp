#include <fstream>
#include <stack>
#include <vector>

using namespace std;

vector<int> G[100001];
bool used[100001];

void dfs(int v) {

    stack<int> stack;
    stack.push(v);
    used[v] = true;

    while (!stack.empty()) {

        int u = stack.top();
        stack.pop();

        for (int i = 0; i < G[u].size(); i++) {
            int to = G[u][i];

            if (!used[to]) {
                used[to] = true;
                stack.push(to);
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, m; fin >> n >> m;
    int a, b;

    for (int i = 1; i <= m; i++) {

        fin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    }
    fout << ans << ' ';
}