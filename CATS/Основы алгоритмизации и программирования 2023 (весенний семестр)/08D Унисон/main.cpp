#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int isGlasn[256] = {};
    isGlasn['a']=isGlasn['u']=isGlasn['e']=isGlasn['o']=isGlasn['i']=isGlasn['y']=isGlasn['A']=isGlasn['U']=isGlasn['O']=isGlasn['E']=isGlasn['I']=isGlasn['Y']=1;

    int N, M;

    string a;

    vector<pair<int, bool>> arrN, arrM;

    fin >> N >> M;
    getline(fin, a);

    for (int i = 0; i < N; i++) {
        getline(fin, a);
        int num = 0;
        bool voskl = false;

        for (char j : a) {
            if (isGlasn[j]) num++;

            if (j == '!') voskl = true;
        }
        arrN.push_back(make_pair( num, voskl ));
    }

    for (int i = 0; i < M; i++) {
        getline(fin, a);
        int num = 0;
        bool voskl = false;

        for (char j : a) {
            if (isGlasn[j]) num++;

            if (j == '!') voskl = true;
        }
        arrM.push_back({ num, voskl });
    }

    vector<vector<int>> memorize(M);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            if (arrN[j].first == arrM[i].first && arrN[j].second == arrM[i].second) {
                memorize[i].push_back(arrN[j].first);
            }

            else memorize[i].push_back(0);

            if (i > 0 && j > 0) {
                memorize[i][j] += memorize[i - 1][j - 1];

                int max;

                if(memorize[i - 1][j] > memorize[i][j - 1]) max = memorize[i - 1][j];
                else max = memorize[i][j - 1];

                if(memorize[i][j] > max) memorize[i][j] = memorize[i][j];
                else memorize[i][j] = max;
            }
            else {
                if(i > 0 && memorize[i][j] <= memorize[i - 1][j]) memorize[i][j] = memorize[i - 1][j];

                if(j > 0 && memorize[i][j] <= memorize[i][j - 1]) memorize[i][j] = memorize[i][j - 1];
            }
        }
    }
    fout << memorize[M - 1][N - 1];
}
