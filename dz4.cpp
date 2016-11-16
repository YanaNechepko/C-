#include <iostream>
#include <cstdlib>
using namespace std;

void dig_trench( int** a, int n)
{
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
        a[i][j] = abs(i-j);
        cout<< a[i][j] <<"  ";
        }
        cout<<endl;
    }
}
int main ()
{
    int a;
    cin>> a;
  int** trench=new int*[a];
    for(int i=0;i<a;i++)
  trench[i]=new int[a];
    dig_trench( trench, a);
    delete [] trench;
    return 0;
}
