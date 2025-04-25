#include <fstream>
#include <iostream>

using namespace std;

void siftUpMax(long long mass [], long long index, long long countEl)
{
    while(mass[index] > mass[(index - 1) / 2])
    {
        swap(mass[index], mass[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void siftDownMax(long long mass [], long long index, long long countEl)
{
    while (2 * index + 1 < countEl)
    {
        long long leftIndex = 2 * index + 1;
        long long rightIndex = 2 * index + 2;

        long long subIndex = leftIndex;
        if(rightIndex < countEl and mass[rightIndex] > mass[leftIndex])
        {
            subIndex = rightIndex;
        }
        if(mass[index] >= mass[subIndex])
        {
            break;
        }
        swap(mass[index], mass[subIndex]);
        index = subIndex;
    }
}

void buildHeapMax(long long mass [], long long countEl)
{
    for(long long i = countEl / 2; i >= 0; --i)
    {
        siftDownMax(mass, i, countEl);
    }
}

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    long long n, m;
    fin >> n >> m;

    long long mass[n];

    for (long long i = 0; i < n; i++) {

        fin >> mass[i];
    }
    buildHeapMax(mass, n);

    for (long long i = 0; i < m; ++i) {

        mass[0] /= 10;

        siftDownMax(mass, 0, n);
    }

    long long res = 0;

    for(long long i = 0; i < n; i++){
        res += mass[i];
    }

    fout<<res;
}