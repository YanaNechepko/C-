#include <iostream>
using namespace std;
int search(int a, int b);
struct ABC {
    int x;
    int y;
};
ABC s[101] = {};
int main()
{
    int n = 0;    //îñü X
    int m = 0;    //îñü Y
    cin >> n;
    cin >> m;
    int k = 0;
    cin >> k;

    for(int i = 0; i < k; i++)        //ââîäèì êîîðäèíàòû ïðîõîäíûõ êâàðòàëîâ
    {
        cin >> s[i].x;
        cin >> s[i].y;
    }
    int **l = new int* [n+1];
    for (int count = 0; count < n+1; count++)
        l[count] = new int [m+1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            l[i][j] = 0;        //ïðîñòî çàïîëíÿåì ìàññèâ íóëÿìè
        }
    }
    int b = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)        //èäåì ñíèçó ââåðõ è ñëåâà íàïðàâî
        {
            l[i][j] = l[i-1][j];
            if (b == 1) { l[i][j] = l[i][j-1]; }
            if (search(i, j) && l[i-1][j] == l[i][j-1]) { l[i][j] += 1; b = 1; }
            if (l[i][j] < l[i-1][j]) l[i][j] = l[i-1][j];
        }
        b = 0;
    }
    long long res = 0;
    res = (m + n) * 100 - l[n][m] * 58.5;    // â l[n][m] õðàíèòñÿ êîëè÷åñòâî ïðîõîäíûõ êâàðòàëîâ
    cout << res;
    for (int count = 0; count < n+1; count++) delete [] l[count];
    system("pause");
    return 0;
}
int search(int a, int b)    //ôóíêöèÿ ïîèñêà ïðîõîäíûõ êâàðòàëîâ
{
    for(int i = 0;; i++)
    {
        if (s[i].x == a && s[i].y == b) return 1;
        if (s[i].x == 0 && s[i].y == 0) break; //áàðüåð
    }
    return 0;
}
