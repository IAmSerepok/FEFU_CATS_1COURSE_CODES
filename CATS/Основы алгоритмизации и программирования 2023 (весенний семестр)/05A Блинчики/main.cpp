#include <fstream>

int main(){

    std::ifstream inf("input.txt");
    std::ofstream sup("output.txt");

    int n, res = 0;
    inf >> n;

    char a,b;
    inf >> a;

    for(int i = 1; i < n; i++){

        inf >> b;
        if(a != b) {

            res++;
            a = b;
        }
    }
    if(b == 'B') res++;

    sup << res;
}