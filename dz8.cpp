#include <iostream>
using namespace std;
int GCD(int a, int b)
{
	int c;
	if (a % b == 0)
	{
		return (b);
	}
	else
	{
		c = a % b;
		a = b;
		b = c;
		return(GCD(a, b));
	}
}
int main()
{
	int n, k;
	cin >> n;
	k = 0;
	for (int i = 1; i < n; i++)

		if (GCD(i, n) == 1)
		{
			k++;
			cout << i << " ";
		}
	cout << endl << "Count - " << k;
	cout << endl;
	system("pause");
	return 0;
}
