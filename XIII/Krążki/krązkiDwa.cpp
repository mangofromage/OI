#include <iostream>
using namespace std;

typedef long long int LL;

int main()
{
    ios_base::sync_with_stdio(0);
    LL n, m;
    cin >> n >> m;
    LL *minimum = new LL[n + 2];
    minimum[0] = 1 << 30;
    LL d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d;
        if (d < minimum[i - 1])
            minimum[i] = d;
        else
            minimum[i] = minimum[i - 1];
    }
    minimum[n + 1] = 0;

    LL br = n + 1, k;
    for (int i = 0; i < m; ++i)
    {
        cin >> k;
        if (br > 0)
            --br;
        while (minimum[br] < k)
            --br;
    }
    cout << br << '\n';
    return 0;
}