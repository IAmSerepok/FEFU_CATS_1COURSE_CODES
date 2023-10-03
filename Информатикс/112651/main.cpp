#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // константа, обозначающая бесконечность

int main() {
    int n; // количество вершин
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int a, b; // начальная и конечная вершины
    cin >> a >> b;
    a--, b--; // уменьшаем на 1, чтобы вершины нумеровались с 0

    // алгоритм Дейкстры
    vector<int> dist(n, INF); // вектор расстояний до каждой вершины
    vector<int> parent(n, -1); // вектор предков для хранения пути
    dist[a] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // очередь приоритетов
    q.push(make_pair(0, a));

    while (!q.empty()) {
        int v = q.top().second;
        int d = q.top().first;
        q.pop();
        if (d > dist[v]) { // если текущее расстояние до вершины v уже больше, чем пришли, то пропускаем эту вершину
            continue;
        }
        for (int to = 0; to < n; to++) {
            if (graph[v][to] != 0 && dist[v] + graph[v][to] < dist[to]) {
                dist[to] = dist[v] + graph[v][to];
                parent[to] = v;
                q.push(make_pair(dist[to], to));
            }
        }
    }

    if (dist[b] == INF) { // если путь не найден
        cout << 0 << endl;
    } else {
        vector<int> path;
        for (int v = b; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end()); // обращаем путь, потому что мы запоминали предков с конца
        cout << dist[b] << endl;
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] + 1 << " "; // увеличиваем на 1, чтобы вершины нумеровались с 1
        }
        cout << endl;
    }
}