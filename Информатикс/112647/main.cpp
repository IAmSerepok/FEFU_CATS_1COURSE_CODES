#include <iostream>
#include <set>
#include <string>

using namespace std;

int N;
bool arr[1001][1001];
int ocup[1001];
string name[1001];

int main() {

    int r1 = 0, r2 = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }


    int num = 0;
    for(int i = 0; i < N; i++){

        string a;
        cin >> a;
        int fl = 0;

        for(int j = 0; j < num; j++){

            if(name[j] == a){

                ocup[i] = j;
                fl = 1;
                break;
            }
        }

        if(fl == 0){

            name[num] = a;
            ocup[i] = num;
            num++;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){

            if(arr[i][j] != 0){

                if(ocup[i] == ocup[j]) r1++;
                else r2++;
            }
        }
    }

    cout << r1 << ' ' << r2;
}