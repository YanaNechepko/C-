#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

const int size = 20;     //размерность массива, который нужно сортировать
const int hor = 10, ver = size;     //размерность массива блоков
void bucketSort(int[size]);     //функция, которая сортирует данные массива
void newBuckets(int[][ver]);     //функция задающей начальные значения блочному массиву
void printArray(int[size]);     //функция, которая выводит массив на экран

using namespace std;

int main()
{
    int array[size];     //выделяем память для массива, который будет содержать неотсортированные данные
    srand(time(NULL));
    for(int i = 0; i < size; i++)     //заполняем массив случайными числами в интервале от 1 до 100
    array[i] = rand() % 300;
    cout << "Nosorted array: " << endl << endl;
    printArray(array);     //выводим на печать неотсортированный массив
    bucketSort(array);     //отправляем массив в функции, которая его отсортирует с помощью "блочной сортировки"
    cout << "Sorted array: " << endl << endl;
    printArray(array);     //выводим на печать отсортированный массив
    return 0;
}
void bucketSort(int array[size])
{
    int buckets[hor][ver];
    int ostatok, temp;
    int count;     //счетчик ячеек исходного массива чисел
    for(int x = 1; x <= 100; x *= 10)     //обработка единиц, десятков, сотен и т.д. чисел исходного массива
    {
        newBuckets(buckets);     //задаем начальные значения массиву блоков
        count = 0;     //обнуляем счетчик ячеек исходного массива чисел
        for(int i = 0; i < size; i++)     //помещаем каждое значение одномерного массива в строку массива блоков, основываясь на значении его первого разряда
        {                                      //"распределяющий проход"
            temp = array[i] / x;
            ostatok = temp % 10;
            buckets[ostatok][i] = array[i];
        }
        for(int i = 0; i < hor; i++)     //копируем значения обратоно в исходный массив
        {                                      //"собирающий проход"
            for(int j = 0; j < ver; j++)
            {
                if(buckets[i][j] != -1)     //игнорируем пустые (незаполненные) ячейки
                {
                    array[count] = buckets[i][j];     //если число в массиве блоков не нулевое, то копируем его в исходный массив
                    count++;     //служит для того, чтобы выбирать следующую ячейку исходного массива чисел
                }
            }
        }
    }
}
void newBuckets(int buckets[][ver])
{
    for(int i = 0; i < hor; i++)     //обнуляем массив блоков
    for(int j = 0; j < ver; j++)
    buckets[i][j] = -1;
}
void printArray(int array[size])
{
    for(int i = 0; i < size; i++)
    {
        cout << setw(5) << array[i];
        if((i + 1) % 10 == 0)
            cout << endl << endl;
    }
    cout << endl << endl;
}
