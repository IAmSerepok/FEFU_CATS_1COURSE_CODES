#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    set <int> arr;

    while(1){

        int a;
        fin >> a;

        if(a > 0) arr.insert(a);
        if(a < 0 && arr.find(abs(a)) != arr.end()) arr.erase(arr.find(abs(a)));
        if(a == 0){

            for (const auto &i:arr)
            {
                fout << i << ' ';
            }
            break;
        }
    }
}