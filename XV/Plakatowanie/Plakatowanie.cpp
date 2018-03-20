#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ile(int *wys, int n)
{
    vector<int> s;
    int ile = 0;
    for(int i = 0; i < n; ++i)
    {
        for(;s.size() > 0 && s.back() > wys[i];)
        {
            s.pop_back();
        }
        if(s.size() == 0 || s.back() < wys[i])
        {
            s.push_back(wys[i]);
            ++ile;
        }
    }
    return ile;
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

    cout << ile(wysokosci, n) << endl;
    return 0;
}