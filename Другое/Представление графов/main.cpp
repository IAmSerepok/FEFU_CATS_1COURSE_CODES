#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

struct triplets{
    int a,b,c;
};

int main() {

    int v, r;

    cin>>v>>r;

    int smej[v+1][v+1];
    int inc[v+1][r+1];

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            smej[i][j] = 0;

    for(int i = 0; i < v; i++)
        for(int j = 0; j < r; j++)
            inc[i][j] = 0;

    vector <pair<int, int>> smej_list[v+1];
    vector <triplets> r_list;

    int a,b,c;

    for(int i = 0; i < r; i++) {

        cin >> a >> b >> c;

        triplets t;
        t.a = a;
        t.b = b;
        t.c = c;

        pair<int, int> p;
        p.first = b;
        p.second = c;

        r_list.push_back(t);
        smej[a - 1][b - 1] = c;
        smej_list[a-1].push_back(p);
        inc[a-1][i] = c;
        inc[b-1][i] = (-1)*c;
    }

    for(int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            int buff = smej[i][j];
            cout<<setw(3)<<buff<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i = 0; i < v; i++) {
        for (int j = 0; j < r; j++) {
            int buff = inc[i][j];
            cout<<setw(3)<<buff<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i = 0; i < r; i++){
        cout<<r_list[i].a<<" <-> "<<r_list[i].b<<"  wight = "<<r_list[i].c<<'\n';
    }
    cout<<'\n';

    for(int i = 1; i <= v; i++){
        cout<<i<<" (";
        for(int j = 0; j < smej_list[i - 1].size(); j++){

            pair <int,int> a = smej_list[i - 1][j];
            cout<< a.first << "  wight = " << a.second << "; ";
        }

        cout<<")\n";
    }
}
