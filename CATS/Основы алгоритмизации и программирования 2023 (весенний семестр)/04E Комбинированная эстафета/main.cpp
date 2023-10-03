#include <fstream>

void permutations(float (&line)[4][4], int finalRes[], int res[], int Last, float &minTime, float time, int First){

    if(First == Last){

        if(time + line[3][3] < minTime){

            minTime = time + line[3][3];

            for(int i = 0; i < 4; i++)
                finalRes[i] = res[i];
        }
    }
    else{

        for (int index = First; index <= Last; index++){

            if(index > First){

                std::swap(line[First], line[index]);
                std::swap(res[First], res[index]);
            }

            permutations(line, finalRes, res, Last, minTime, time + line[First][First], First + 1);

            if(index > First){
                std::swap(res[First], res[index]);
                std::swap(line[First], line[index]);
            }
        }
    }
}

int main()
{
    std::ifstream inf("input.txt");
    std::ofstream outf ("output.txt");

    float massTime[4][4];

    for (int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            inf >> massTime[j][i];

    float minTime = 500;
    int finalRes[4] = {1, 2, 3, 4}, res[4] = {1, 2, 3, 4};

    permutations(massTime, finalRes, res, 3, minTime, 0, 0);

    for(int i = 0; i < 4; i++)
        outf << finalRes[i] << " ";
}
