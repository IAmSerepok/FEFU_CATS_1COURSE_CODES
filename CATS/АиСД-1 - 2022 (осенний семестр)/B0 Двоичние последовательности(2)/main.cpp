#include <string>
#include <fstream>
#include <iostream>

using namespace std;
ofstream fout("output.txt");
static string str="";

void func(int n){

    if(n==0){

        fout << str << endl;
        return;
    }
    str.push_back('0');

    func(n-1);

    str.pop_back();
    str.push_back('1');

    func(n-1);

    str.pop_back();
}

int main() {

    ifstream fin("input.txt");

    int n;

    fin>>n;

    func(n);
}
