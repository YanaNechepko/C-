#include <iostream>
using namespace std;

int FE(int n) {
int i=0;
int m=1;
for (i=2; i <= n/2; i++)
if (n % i == 0) {
n/=i;
while (n % i == 0) {
m*=i;
n/=i;
}
if (n==1) return m*(i-1);
else return m*(i-1)*FE(n);
}
return n-1;
}
int main() {
int n=0;
cin>>n;
cout<<FE(n);
return 0;
}
