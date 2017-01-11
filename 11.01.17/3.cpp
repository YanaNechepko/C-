#include <iostream>
using namespace std;

 void incredible_sort (int n, int k)  {
int* a = new int [k];
int b;
    for (int i = 0; i < k; i ++)
        a[i]=0;
    for (int i = 0; i < n; i++)
        {
           cin>>b;
           a[b-1]++;
        }
    for (int i = k-1; i > -1; i--)
        for (int j = 0; j < a[i]; j++)
            cout<<i+1<<' ';
 }
int main() {
    int n;
    int k;
    cin>>n>>k;
    incredible_sort ( n , k );
    return 0;
}
