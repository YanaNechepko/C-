#include <iostream>
using namespace std;

bool pro(int a)
{
    for(int i=2;i*i<=a;i++)
		if(a%i==0)
			return false;
	return true;
}
 void delete_duplicates(int* array, int n)
 {
     bool flag[n];
     for (int i=0; i < n; i++)
        flag[i]=true;
     for ( int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
           if ( array[i]==array[j] and i!=j and pro(array[i]) and array[i]!=0 )
           flag[i]=false;
    for (int i = 0; i < n; i++)
        if ( flag[i])
        cout<<array[i]<<" ";
     }
int main()
{
    int n;
    cin>> n;
    int* array = new int [n];
    for (int i = 0; i < n; i++)
        cin>>array[i];
    delete_duplicates (array, n);
    delete [] array;
    return 0;
}
