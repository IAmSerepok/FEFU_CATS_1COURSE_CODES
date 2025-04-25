#include <vector>
#include <fstream>

using namespace std;

int main(){

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<pair<string, vector<int>>> colors;
    int N; fin >> N;
    int fl;

    for (int i = 0; i < N; ++i) {
        string str;
        fin >> str;
        fl = 0;

        for (int j = 0; j < colors.size(); j++) {
            pair<string, vector<int>>& buff = colors[j];
            if (buff.first == str) {
                buff.second.push_back(i);
                fl = 1;
                break;
            }
        }

        if (fl == 0) {
            colors.emplace_back(str, vector<int>());
            colors.back().second.push_back(i);
        }
    }

    int K, min;
    int flag1, flag2;
    fin >> K;

    for (int k = 0; k < K; k++) {

        string firstColor, secondColor;
        fin >> firstColor >> secondColor;
        min = INT32_MIN;
        flag1 = flag2 = 0;

        vector<int> poss1, poss2;
        for (int j = 0; j < colors.size(); j++) {
            pair<string, vector<int>>& buff = colors[j];

            if (buff.first == firstColor) {
                flag1 = 1;
                poss1 = buff.second;
            }

            if (buff.first == secondColor) {
                flag2 = 1;
                poss2 = buff.second;
            }
        }

        if (flag1 == 0 || flag2 == 0) {
            fout << "-1\n";
            continue;
        }

        if (firstColor == secondColor) {

            if (poss1.size() == 1) {
                fout << "-2\n";
                continue;
            }

            int min = poss1[1] - poss1[0];
            for (int i = 1; i < poss1.size() - 1; i++) {

                if (poss1[i + 1] - poss1[i] < min) {
                    min = poss1[i + 1] - poss1[i];

                    if (min == 1) {
                        break;
                    }
                }
            }

            min--;
            fout << min << '\n';
            continue;
        }

        int j = 0, i = 0;

        min = abs(poss1[0] - poss2[0]);

        for (;i < poss1.size() || j < poss2.size();) {

            if (poss1[i] > poss2[j]) j++;
            else i++;

            if (i >= poss1.size() || j >= poss2.size()) break;

            if (min >= abs(poss1[i] - poss2[j])) min = abs(poss1[i] - poss2[j]);
        }
        min--;
        fout << min << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}