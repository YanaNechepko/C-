#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

const int size = 20;     //����������� �������, ������� ����� �����������
const int hor = 10, ver = size;     //����������� ������� ������
void bucketSort(int[size]);     //�������, ������� ��������� ������ �������
void newBuckets(int[][ver]);     //������� �������� ��������� �������� �������� �������
void printArray(int[size]);     //�������, ������� ������� ������ �� �����

using namespace std;

int main()
{
    int array[size];     //�������� ������ ��� �������, ������� ����� ��������� ����������������� ������
    srand(time(NULL));
    for(int i = 0; i < size; i++)     //��������� ������ ���������� ������� � ��������� �� 1 �� 100
    array[i] = rand() % 300;
    cout << "Nosorted array: " << endl << endl;
    printArray(array);     //������� �� ������ ����������������� ������
    bucketSort(array);     //���������� ������ � �������, ������� ��� ����������� � ������� "������� ����������"
    cout << "Sorted array: " << endl << endl;
    printArray(array);     //������� �� ������ ��������������� ������
    return 0;
}
void bucketSort(int array[size])
{
    int buckets[hor][ver];
    int ostatok, temp;
    int count;     //������� ����� ��������� ������� �����
    for(int x = 1; x <= 100; x *= 10)     //��������� ������, ��������, ����� � �.�. ����� ��������� �������
    {
        newBuckets(buckets);     //������ ��������� �������� ������� ������
        count = 0;     //�������� ������� ����� ��������� ������� �����
        for(int i = 0; i < size; i++)     //�������� ������ �������� ����������� ������� � ������ ������� ������, ����������� �� �������� ��� ������� �������
        {                                      //"�������������� ������"
            temp = array[i] / x;
            ostatok = temp % 10;
            buckets[ostatok][i] = array[i];
        }
        for(int i = 0; i < hor; i++)     //�������� �������� �������� � �������� ������
        {                                      //"���������� ������"
            for(int j = 0; j < ver; j++)
            {
                if(buckets[i][j] != -1)     //���������� ������ (�������������) ������
                {
                    array[count] = buckets[i][j];     //���� ����� � ������� ������ �� �������, �� �������� ��� � �������� ������
                    count++;     //������ ��� ����, ����� �������� ��������� ������ ��������� ������� �����
                }
            }
        }
    }
}
void newBuckets(int buckets[][ver])
{
    for(int i = 0; i < hor; i++)     //�������� ������ ������
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
