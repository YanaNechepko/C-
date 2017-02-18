#include <iostream>
#include <windows.h>

using namespace std;

class my_vector
{
private:
	double *arr;
	int arr_Size;
public:

    my_vector()
	{
		this->arr_Size = 0;
		this->arr = new double[this->arr_Size];
	}

	void push_back2(int data)
	{
		double *result = new double[++this->arr_Size];
		for(int i = 0; i < this->arr_Size; i++)
		{
			if(i != this->arr_Size-1)
			{
				result[i] = this->arr[i];
			}
			else
			{
				result[i] = data;
				break;
			}
		}
		delete[] this->arr;
		this->arr = result;
	}

	int pop()
	{
		return this->pop_index(this->arr_Size-1);
	}

	void my_clear()
	{
		if(this->arr != NULL)
		{
			this->arr = NULL;
			this->arr_Size = NULL;
		}
		this->arr_Size = 0;
		this->arr = new double[this->arr_Size];
	}

	int operator [](int index)
	{
		return this->arr[index];
	}

	int my_size()
	{
		return this->arr_Size;
	}

	void push_index(int data, int index)
	{
		int temp = this->arr_Size;
		this->arr_Size = (this->arr_Size >= index) ? (++this->arr_Size) : (this->arr_Size + (index - this->arr_Size));
		double *result = new double[this->arr_Size];
		int arrIndex = 0;
		for(int i = 0; i < this->arr_Size; i++)
		{
			if(i == index)
			{
				result[i] = data;
				continue;
			}
			if(arrIndex != temp)
			{
				result[i] = this->arr[arrIndex++];
			}
		}
		delete[] this->arr;
		this->arr = result;
	}

	int pop_index(int index)
	{
		double *result = new double[--this->arr_Size];
		int result_item;
		int result_index = 0;
		for(int i = 0; i < this->arr_Size+1; i++)
		{
			int item = this->arr[i];
			if(index == i)
			{
				result_item = item;
				continue;
			}
			result[result_index++] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = result;
		return result_item;
	}

	~my_vector()
    {
        delete [] arr;
    }
};
