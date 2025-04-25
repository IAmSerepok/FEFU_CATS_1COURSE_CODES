#include <fstream>

using namespace std;

void siftUpMax(int mass [], int massIndexes[], int massOrigin[], int index){

    while(mass[index] > mass[(index - 1) / 2]){

        swap(mass[index], mass[(index - 1) / 2]);
        swap(massIndexes[index],massIndexes[(index - 1) / 2]);
        swap(massOrigin[massIndexes[index]], massOrigin[massIndexes[(index - 1) / 2]]);
        index = (index - 1) / 2;
    }
}

void siftDownMax(int mass [], int massIndexes[],int massOrigin[], int index, int countEl){

    while (2 * index + 1 < countEl){

        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        int subIndex = leftIndex;

        if(rightIndex < countEl and mass[rightIndex] > mass[leftIndex])
            subIndex = rightIndex;

        if(mass[index] >= mass[subIndex])
            break;

        swap(mass[index], mass[subIndex]);
        swap(massIndexes[index],massIndexes[subIndex]);
        swap(massOrigin[massIndexes[index]], massOrigin[massIndexes[subIndex]]);
        index = subIndex;
    }
}

void buildHeapMax(int mass [], int massIndexes [], int massOrigin[], int countEl){

    for(int i = countEl / 2; i >= 0; --i)
        siftDownMax(mass, massIndexes, massOrigin, i, countEl);
}

int main() {
    ofstream outf("output.txt");
    ifstream inf("input.txt");
    int countWorkers, countDiff;
    inf >> countWorkers >> countDiff;
    int massWorkers[countWorkers];

    int massIndexes[countWorkers];
    int massOrigin[countWorkers];

    for (int i = 0; i < countWorkers; i++) {

        inf >> massWorkers[i];
        massIndexes[i] = i;
        massOrigin[i] = i;
    }
    buildHeapMax(massWorkers, massIndexes, massOrigin, countWorkers);

    ofstream outf("output.txt");

    for (int i = 0; i < countDiff; ++i) {

        int index, diff;
        inf >> index >> diff;
        index = massOrigin[index - 1];

        massWorkers[index] += diff;
        if (diff > 0) {
            siftUpMax(massWorkers, massIndexes, massOrigin, index);
        } else {
            siftDownMax(massWorkers, massIndexes, massOrigin, index, countWorkers);
        }
        outf << massWorkers[0] << endl;
    }
}