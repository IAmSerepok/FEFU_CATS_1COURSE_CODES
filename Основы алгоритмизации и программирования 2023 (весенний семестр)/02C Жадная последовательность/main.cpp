#include <bits/stdc++.h>

using namespace std;

bool cmp(int mass[], int indexes[], int ind1, int ind2){

    if(mass[ind1] == mass[ind2]) return indexes[ind1] > indexes[ind2];
    else return mass[ind1] > mass[ind2];
}

void siftUpMin(int mass[], int indexes[], int index, int countEl) // Поднимаем элемент с индексом index вверх по куче
{
    while(mass[index] < mass[(index - 1) / 2]) // Пока значение текущего элемента меньше значения родителя
    {
        // Меняем местами элементы и переходим к новому индексу
        swap(mass[index], mass[(index - 1) / 2]);
        swap(indexes[index], indexes[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void siftDownMin(int mass[], int indexes[], int index, int countEl) // Опускаем элемент с индексом index вниз по куче
{
    while (2 * index + 1 < countEl) // Пока у элемента есть дети
    {
        // Индексы правого и левого потомка
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        int subIndex = leftIndex;
        if(rightIndex < countEl and !cmp(mass, indexes, rightIndex ,leftIndex)) // Если существует правый индекс и правое значение меньше левого
        {
            subIndex = rightIndex;
        } // Выбор наименьшего ребёнка
        if(!cmp(mass, indexes, index, subIndex))
        {
            break;
        } // Если текущий элемент меньше или равен его детям, то прерываем цикл
        swap(mass[index], mass[subIndex]);
        swap(indexes[index], indexes[subIndex]);
        index = subIndex; // Индекс меняемого элемента
    }
}
void buildHeapMin(int mass[], int indexes[], int countEl) // Создаём минимальную кучу
{
    // Проходим по половине элементов массива, начиная с конца и "опускаем" каждый элемент вниз по куче
    for(int i = countEl / 2; i >= 0; --i)
    {
        siftDownMin(mass, indexes, i, countEl);
    }
}

void q_sort(int mas[], int arr[], int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Опорный(центральный) элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть

        //В левой части массива
        //пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int buffer = mas[i];
            mas[i] = mas[j];
            mas[j] = buffer;

            buffer = arr[i];
            arr[i] = arr[j];
            arr[j] = buffer;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //левый подмассив
        q_sort(mas, arr, j + 1);
    }
    if (i < size) {
        //правый подмассив
        q_sort(&mas[i], &arr[i], size - i);
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    int heap[n], arr[n], size = n, num = 0;

    for(;num < n; num++) arr[num] = num;

    for(int i = 0; i < n; i++) fin >> heap[i];

    buildHeapMin(heap, arr, size);

    for(int i = 0; i < m; i++){

        int sum = heap[0];
        heap[0] = heap[size-1];
        arr[0] = arr[size-1];
        arr[size-1] = INT32_MAX;
        size--;
        siftDownMin(heap, arr, 0, size);
        heap[0] += sum;
        arr[0] = num;
        num++;
        siftDownMin(heap,arr, 0, size);
    }
    q_sort(arr, heap, size);
    for(int i = 0; i < size; i++) fout << heap[i] << ' ';
}