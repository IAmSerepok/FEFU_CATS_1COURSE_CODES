#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ifstream fin ("input.txt");
    ofstream outf("output.txt");
    
    int N;
    int M, K;

    set<pair<string, string>> mass;
    
    fin >> N;

    for(int index = 0; index < N; index++)
    {
        string item;
        fin >> item;
    }

    fin >> M;

    for(int index = 0; index < M; index++)
    {
        string item1, item2;
        fin >> item1 >> item2;
        mass.insert(make_pair(item1, item2));
    }

    fin >> K;

    for(int index = 0; index < K; index++)
    {
        string item1, item2;
        fin >> item1 >> item2;
        if(mass.find(make_pair(item1, item2))!=mass.end())
        {
            outf << "1 ";
        }
        else if(mass.find(make_pair(item2, item1))!=mass.end())
        {
            outf << "2 ";
        }
        else
        {
            outf << "0 ";
        }
    }
}
