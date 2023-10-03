#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inf ("input.txt");
    int countPlanes, timeUnload;
    inf >> countPlanes >> timeUnload;
    int massPlanes[countPlanes];
    for(int i = 0; i < countPlanes; i++)
        inf >> massPlanes[i];

    inf.close();
    sort(massPlanes, massPlanes + countPlanes);

    int timeSum = timeUnload + massPlanes[0]; // Время разгрузки последнего + время полёта первого
    for(int i = 0; i < countPlanes - 1; i++)
    {
        timeSum += timeUnload;
        if (massPlanes[i + 1] - massPlanes[i] > timeUnload)
        {
            timeSum += massPlanes[i + 1] - massPlanes[i] - timeUnload;
        }
    }
    ofstream outf ("output.txt");
    outf << timeSum;
    outf.close();
}