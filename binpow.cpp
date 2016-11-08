#include <iostream>
using namespace std;

int binpow (double a, int n) {
if (n==0) {
return 1;
}
if (n%2==0) {
int b=binpow(a,n/2);
return b*b;
}
else {
return binpow (a,n-1)*a;
}
}

int main () {
double a=0;
int n=0;
cin>>a>>n;
cout<<binpow(a,n);
return 0;
}
