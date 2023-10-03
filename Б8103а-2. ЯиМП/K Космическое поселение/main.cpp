#include <fstream>

using namespace std;

int main() {

    ifstream fin("space.in");

    long long n, a, b, w, h, t, res, d = 0, buf = 0;
    fin >> n >> a >> b >> w >> h;
    if (a > b){

        t = a;
        a = b;
        b = t;
    }

    if (w > h){

        t = w;
        w = h;
        h = t;
    }

    res = (w - a) / 2;

    for(;res > d;){

        buf = d + (res - d) / 2;

        if (((w / (b + 2 * buf)) * (h / (a + 2 * buf)) >= n) || ((w / (a + 2 * buf)) * (h / (b + 2 * buf)) >= n))
                d = buf + 1;
        else
            res = buf - 1;
    }
    if(!((((w / (a + 2 * res)) * (h / (b + 2 * res)) >= n) || ((w / (b + 2 * res)) * (h / (a + 2 * res))) >= n)))
        res--;

    ofstream fout("space.out");

    fout << res;
}
