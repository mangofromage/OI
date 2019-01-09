#include <iostream>
#include <algorithm>
#include <cstdlib>

typedef long long int LL;
const int maxfib = 87;

LL fib[maxfib] = {0};

void init_fib()
{
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < maxfib; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    init_fib();
    int p = 0;
    std::cin >> p;
    for (int a_count = 0, result = 0; a_count < p; ++a_count, result = 0)
    {
        LL k = 0;
        std::cin >> k;
        while (k > 0)
        {
            LL m = k;
            for (int i = 0; i < maxfib; ++i)
                m = std::min(m, std::abs(k - fib[i]));
            k = m;
            ++result;
        }
        printf("%d\n", result);
    }
    return 0;
}
