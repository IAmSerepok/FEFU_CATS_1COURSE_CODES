#include <iostream>

using namespace std;

const unsigned short p = 127;

long long calcCost(const long long massHash[], const long long massMul[], int beginIndex, int endIndex, int beginSecondStr)
{
    if(beginIndex == 0)
        return massHash[endIndex] * massMul[beginSecondStr];
    else
        return (massHash[endIndex] - massHash[beginIndex - 1]) * massMul[beginSecondStr];
}

int main()
{
    string str;
    int m;
    cin >> str >> m;

    long long massHash [str.length()]; massHash[0] = int(str[0]);

    long long massMul[str.length()]; massMul[0] = 1;

    for (int index = 1; index < str.length(); ++index)
    {
        massMul[index] = massMul[index - 1] * p;
        massHash[index] = massHash[index - 1] + int(str[index]) * massMul[index];
    }

    for (int i = 0; i < m; i++)
    {
        int begin1, end1, begin2, end2;

        cin >> begin1 >> end1 >> begin2 >> end2;
        begin1 --; end1--; begin2--; end2--;

        if (begin1 == begin2 & end1 == end2)
        {
            cout << "Yes\n";
        }
        else if(end1 - begin1 == end2 - begin2)
        {
            bool status = calcCost(massHash, massMul, begin1, end1, begin2) == calcCost(massHash, massMul, begin2, end2, begin1);
            if(status == true){
                    cout << "Yes\n";
            }
            if(status == false){
                cout << "No\n";
            }
        }
        else
        {
            cout << "No\n";
        }
    }
}