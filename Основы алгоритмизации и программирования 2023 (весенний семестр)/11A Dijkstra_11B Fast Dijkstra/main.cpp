#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    ofstream fout("output.txt");
    ifstream fin("input.txt");

    int n, m, s;
    fin >> n >> m >> s;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u-1].emplace_back(v-1, w);
    }

    vector<int> dist(n, INT32_MAX);
    dist[s-1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s-1);


    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (pair<int,int>& buff : adj[u]) {

            int v = buff.first, w = buff.second;

            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int d : dist) {
        if (d != INT32_MAX) fout << d << ' ';
        else fout << "-1 ";
    }
}