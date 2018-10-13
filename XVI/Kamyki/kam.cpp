#include <iostream>
const int MANX = 1000;
int a[MANX + 1];
int d[MANX + 1];

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int m = 0, x = 0;
        std::cin >> m;
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> a[j];
        }
        for (int j = 1; j < m; ++j)
        {
            d[j] = a[m - j + 1] - a[m - j];
        }
        d[m] = a[1];
        for (int j = 1; j <= m; j += 2)
        {
            x ^= d[j];
        }
        printf(x ? "TAK\n" : "NIE\n");
    }
    return 0;
}