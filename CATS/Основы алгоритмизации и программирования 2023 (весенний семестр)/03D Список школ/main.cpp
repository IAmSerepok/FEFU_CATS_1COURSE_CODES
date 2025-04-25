#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ifstream fin("schools.in");
    ofstream fout("schools.out");

    unordered_map <string, int> arr;

    string str, index;

    int count = 0;
    int n;

    fin >> n;

    fin.ignore();

    for (int i = 0; i < n; i++){

        getline(fin, str);

        for (int j = 0; j < str.size(); j++) {

            if ((int)str[j] > 48 && (int)str[j] < 58){

                while ((int)str[j] > 47 && (int)str[j] < 58){

                    index += str[j];
                    j++;
                }

                int val = arr[index];
                val++;
                arr.erase(index);
                arr.insert({ index, val });
                index.clear();

                break;
            }
        }
    }
    for (const auto& it : arr){

        if (it.second < 6)
            count++;
    }

    fout << count << '\n';

    for (const auto& it : arr){

        if (it.second < 6)
        fout << it.first << '\n';
    }

    fin.close();
    fout.close();
}