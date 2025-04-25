#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> coords;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }

    bool is_convex = true;
    int last_sign = 0;

    for (int i = 2; i < n + 2; i++) {
        int j = (i - 1) % n;  // индекс второй вершины
        int k = (i - 2) % n;  // индекс первой вершины
        int x1 = coords[k].first, y1 = coords[k].second;
        int x2 = coords[j].first, y2 = coords[j].second;
        int x3 = coords[i % n].first, y3 = coords[i % n].second;
        int cross_product = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
        int sign;
        if (cross_product > 0) {
            sign = 1;
        } else if (cross_product < 0) {
            sign = -1;
        } else {
            sign = 0;
        }
        if (sign != 0 && sign != last_sign && i > 2) {
            is_convex = false;
            break;
        }
        last_sign = sign;
    }

    if (is_convex) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}