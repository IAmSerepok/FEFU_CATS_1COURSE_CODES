#include <fstream>
#include <vector>

using namespace std;

int main() {

    ofstream fout("output.txt");
    ifstream fin("input.txt");
    
    int n, m, s;
    fin >> n >> m >> s;
    
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        
        fin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--;
        edges[i][1]--;
    }
    
    vector<int> dist(n, INT32_MAX);
    dist[s-1] = 0;
    
    for (int i = 0; i < n-1; i++) {
        
        for (vector<int>& e : edges) {
            
            int u = e[0], v = e[1], w = e[2];
            
            if (dist[u] != INT32_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }
    
    bool has_negative_cycle = false;
    
    for (vector<int>& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != INT32_MAX && dist[u] + w < dist[v]) {
            has_negative_cycle = true;
            break;
        }
    }
    
    for (int d : dist) {
        if (d != INT32_MAX) fout << d << ' ';
        else fout << ' ';
    }
}