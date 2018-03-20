#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ile1(int *wys, int n)
{
    sort(wys, wys + n);
    //for(int i =0 ; i < n; ++i) cout << wys[i] << endl;
    int ile = 0;
    
    for(int i = 0, c = 0; i < n; ++i)
    {
        if(i == 0) c = wys[i];
        int k = i;
        for(; wys[i] == c; ++i);
        if(k < i) ++ile;
        c = wys[i];
    }

    

    return n - ile;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    if(n == 0) return 0;

    int *wysokosci = new int[n];

    for(int i = 0; i < n; ++i)
    {
        int bezuzyteczna = 0;
        cin >> bezuzyteczna;
        cin >> wysokosci[i];
    }

    cout << ile1(wysokosci, n) << endl;
    return 0;
}