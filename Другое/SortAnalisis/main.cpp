#include <iostream>
#include <chrono>
#include <cmath>

void selectionSort(int num[], int size)
{
    int min, buffer; // для поиска минимального элемента и для обмена
    for (int i = 0; i < size - 1; i++)
    {
        min = i; // запоминаем индекс текущего элемента
        // ищем минимальный элемент чтобы поместить на место i-ого
        for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
        {
            if (num[j] < num[min]) // если элемент меньше минимального,
                min = j;       // запоминаем его индекс в min
        }
        buffer = num[i];      // меняем местами i-ый и минимальный элементы
        num[i] = num[min];
        num[min] = buffer;
    }
}

void qsort(int mas[], int size) {
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

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //левый подмассив
        qsort(mas, j + 1);
    }
    if (i < size) {
        //правый подмассив
        qsort(&mas[i], size - i);
    }
}

const int n = 0;

int main()
{
    for(int t = 0; t < 10; t++) {
        const int COUNT = pow(10, n+t);
        int SRAND = 1;

        srand(SRAND);
        int *array = new int[COUNT];
        for (int i = 0; i < COUNT; i++) {
            array[i] = rand();
        }

        using namespace std::chrono;

        auto start = steady_clock::now();

        //qsort(array, COUNT);
        selectionSort(array, COUNT);

        auto end = steady_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);

        std::cout << COUNT << " : " << duration.count() << "ms\n";

    }
}
