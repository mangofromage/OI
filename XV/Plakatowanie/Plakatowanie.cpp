#include <iostream>

using namespace std;

int ile(int *wys, int n, int indeks)
{
    int min = 1 << 31;
    
    int k = indeks;
    for(int i = indeks; wys[i] != 0; ++i, ++k)
    {
        if(wys[i] < min && wys[i] != 0) min = wys[i];
    }
    for(int i = indeks; i < k; ++i)
    {
        wys[i] -= min;
    }

    if(indeks < n) return 1 + ile(wys, n, k + 1);
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >>n;
    if(n == 0) return 0;

    int *wysokosci = new int[n];

    for(int i = 0; i < n; ++i)
    {
        int bezuzyteczna = 0;
        cin >> bezuzyteczna;
        cin >> wysokosci[i];
    }

    cout << ile(wysokosci, n, 0) << endl;
    return 0;
}