#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void siftUpMin(int mass [], int index, int countEl) // Поднимаем элемент с индексом index вверх по куче
{
    while(mass[index] < mass[(index - 1) / 2]) // Пока значение текущего элемента меньше значения родителя
    {
        // Меняем местами элементы и переходим к новому индексу
        swap(mass[index], mass[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void siftDownMin(int mass [], int index, int countEl) // Опускаем элемент с индексом index вниз по куче
{
    while (2 * index + 1 < countEl) // Пока у элемента есть дети
    {
        // Индексы правого и левого потомка
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        int subIndex = leftIndex;
        if(rightIndex < countEl and mass[rightIndex] < mass[leftIndex]) // Если существует правый индекс и правое значение меньше левого
        {
            subIndex = rightIndex;
        } // Выбор наименьшего ребёнка
        if(mass[index] <= mass[subIndex])
        {
            break;
        } // Если текущий элемент меньше или равен его детям, то прерываем цикл
        swap(mass[index], mass[subIndex]);
        index = subIndex; // Индекс меняемого элемента
    }
}

void buildHeapMin(int mass [], int countEl) // Создаём минимальную кучу
{
    // Проходим по половине элементов массива, начиная с конца и "опускаем" каждый элемент вниз по куче
    for(int i = countEl / 2; i >= 0; --i)
    {
        siftDownMin(mass, i, countEl);
    }
}

void siftUpMax(int mass [], int index, int countEl) // Поднять элемент с индексом index вверх по куче
{
    while(mass[index] > mass[(index - 1) / 2]) // Пока значение текущего элемента больше значения родителя
    {
        // Меняем местами элементы и переходим к новому индексу
        swap(mass[index], mass[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void siftDownMax(int mass [], int index, int countEl) // Опускаем элемент с индексом index вниз по куче
{
    while (2 * index + 1 < countEl) // Пока у элемента есть дети
    {
        // Индексы правого и левого потомка
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        int subIndex = leftIndex;
        if(rightIndex < countEl and mass[rightIndex] > mass[leftIndex]) // Если существует правый индекс и правое значение больше левого
        {
            subIndex = rightIndex;
        } // Выбор наибольшего ребёнка
        if(mass[index] >= mass[subIndex])
        {
            break;
        } // Если текущий элемент больше или равен его детям, то прерываем цикл
        swap(mass[index], mass[subIndex]);
        index = subIndex; // Индекс меняемого элемента
    }
}

void buildHeapMax(int mass [], int countEl) // Создаём максимальную кучу
{
    // Проходим по половине элементов массива, начиная с конца и "опускаем" каждый элемент вниз по куче
    for(int i = countEl / 2; i >= 0; --i)
    {
        siftDownMax(mass, i, countEl);
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    int maxHeap[n];
    int minHeap[n];

    int sizeMax = 1;
    int sizeMin = 0;

    int element;
    fin >> element;
    maxHeap[0] = element;
    fout << element << ' ';

    for(int index = 1; index < n; ++index){

        fin >> element;

        if(sizeMax > sizeMin){

            if(element < maxHeap[0]){

                minHeap[sizeMin] = maxHeap[0];
                sizeMin++;
                maxHeap[0] = element;
                siftUpMin(minHeap, sizeMin-1, sizeMin);
                siftDownMax(maxHeap, 0, sizeMax);

            }
            else{

                minHeap[sizeMin] = element;
                sizeMin++;
                siftUpMin(minHeap, sizeMin-1, sizeMin);
            }
            fout << maxHeap[0] << ' ';
        }
        else{

            if(element > minHeap[0]){

                maxHeap[sizeMax] = minHeap[0];
                sizeMax++;
                minHeap[0] = element;
                siftUpMax(maxHeap, sizeMax-1, sizeMax);
                siftDownMin(minHeap, 0, sizeMin);
            }
            else{

                maxHeap[sizeMax] = element;
                sizeMax++;
                siftUpMax(maxHeap, sizeMax-1, sizeMax);
            }
            fout << maxHeap[0] << ' ';
        }
    }
}
