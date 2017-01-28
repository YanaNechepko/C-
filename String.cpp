#include <iostream>
#include <cstring>
using namespace std;

class string2 {
public: char *str;
string2(char *str2) {
    str = new char[strlen(str2)];
    int i = 0;
    for (; i < strlen(str2); i++)   str[i] = str2[i];
    str[i] = '\0';
  }

char get(int i) {
    return str[i];
  }

int find(string s) {
    for (int i = 0; i < strlen(str); i++)
    for (int p = 0, k = i; p < s.length(), k < strlen(str); p++, k++){
        if (str[k] != s[p])  break;
        if (p + 1 == s.length())  return i + 1;
    }
cout << "Not Found" << endl;
return -1;
}

void concat(string s) {
char *strTemp = new char[strlen(str)];
int i = 0;
for (; i < strlen(str); i++)  strTemp[i] = str[i];
strTemp[i] = '\0';
str = new char[strlen(strTemp) + s.length()];
i = 0;
for (; i < strlen(strTemp); i++)  str[i] = strTemp[i];
int k = 0; i = strlen(strTemp);
for (; i < strlen(strTemp) + s.length(); i++, k++)  str[i] = s[k];
str[i] = '\0';
}

void print(){
for (int i = 0; i < strlen(str); i++)cout << str[i];
}
~string2()
{}
};

int main(){
string2 a("New string");
cout << "Our string - "; a.print();
cout << endl << "Output 1 element of string = " << a.get(1);
cout << endl << "Add characters to string..."; a.concat(" - New Life");
cout << endl << "New string - "; a.print();
cout << endl << "On this element string have ''Life'' - " << a.find("Life");
return 0;
}
