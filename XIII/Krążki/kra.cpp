#include <iostream>
#define min(a, b) a < b ? a : b

const int maxn = 300002;
int mini[maxn];

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0,
        m = 0;
    std::cin >> n >> m;
    if (m == n)
    {
        std::cout << "0\n";
        return 0;
    }
    int br = n + 1;
    mini[0] = 1 << 30;
    for (int i = 1, k; i <= n; ++i)
    {
        std::cin >> k;
        mini[i] = min(mini[i - 1], k);
    }
    mini[n + 1] = 0;
    for (int i = 0, k = 0; i < m; ++i)
    {
        std::cin >> k;
        if (br > 0)
            --br;
        while (br > 0 && k > mini[br])
            --br;
    }
    std::cout << br << '\n';
    return 0;
}
