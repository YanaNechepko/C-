#include <iostream>
using namespace std;

int GCD (int a, int b) {
if (b==0) {
return a;
}
if (a==0) {
return b;
}
return GCD(b, a%b);
}

int main() {
int a=0;
int b=0;
int nok=0;
cin>>a>>b>>nok;
if (a==0 or b==0) {
nok=GCD(a,b);
}
else {
nok=a*b/GCD(a,b);
}
cout<<nok<<endl;
return 0;
}
