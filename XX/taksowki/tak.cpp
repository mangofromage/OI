#include <iostream>
#include <algorithm>
typedef long long int ll;

void close(int result = 0)
{
    std::cout << result << '\n';
    exit(0);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    ll d = 0, m = 0, n = 0;
    std::cin >> m >> d >> n;
    ll *x = new ll[n];
    for (int i = 0; i < n; ++i)
        std::cin >> x[i];
    std::sort(x, x + n);
    std::reverse(x, x + n);
    if (x[0] < m - d)
        close();
    int ti = 0;
    for (; ti + 1 < n && x[ti + 1] >= m - d; ++ti)
        ;
    ll ostatnia = x[ti];
    for (int i = ti; i + 1 < n; ++i)
        x[i] = x[i + 1];
    --n;
    ll pozycja = 0;
    for (int i = 0; i < n; ++i)
    {
        if (d - pozycja + d - pozycja + m - d <= ostatnia)
            close(i + 1);
        if (d - pozycja > x[i])
            close();
        pozycja += x[i] - d + pozycja;
        if (pozycja >= m)
            close(i + 1);
        if (pozycja > d)
            pozycja = d;
    }
    if (d - pozycja + d - pozycja + m - d <= ostatnia)
        close(n + 1);
    close();
}