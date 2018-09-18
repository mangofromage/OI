#include <algorithm>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    long long int m = 0, d = 0, n = 0;
    std::cin >> m >> d >> n;
    long long int *x = new long long int[n]{0};
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }

    std::sort(x, x + n);
    std::reverse(x, x + n);

    if (x[0] < m - d)
    {
        std::cout << 0 << "\n";
        return 0;
    }

    int ti = 0;
    while (ti + 1 < n && x[ti + 1] >= m - d)
        ++ti;

    long long int ostatnia = x[ti];
    while (ti + 1 < n)
    {
        x[ti] = x[ti + 1];
        ++ti;
    }
    --n;

    long long int pozycja = 0;

    for (int i = 0; i < n; ++i)
    {
        if (2LL * (d - pozycja) + m - d <= ostatnia)
        {
            std::cout << i + 1 << '\n';
            return 0;
        }
        if (d - pozycja > x[i])
        {
            std::cout << 0 << '\n';
            return 0;
        }
        pozycja += (x[i] - (d - pozycja));
        if (pozycja >= m)
        {
            std::cout << i + 1 << '\n';
            return 0;
        }
        if(pozycja > d)
        {
            pozycja = d;
        }
    }

    if(2LL * (d - pozycja) + m - d <= ostatnia)
    {
        std::cout << n + 1 << '\n';
        return 0;
    }
    std::cout << 0 << '\n';
    return 0;
}