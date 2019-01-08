#include <iostream>

const int MAXN = 1000 * 1000;
int n = 0,
    m = 0,
    d = 0,
    wynik = 0,
    ile_niezgodnych = 0,
    ile_jest[MAXN] = {0},
    ile_powinno_byc[MAXN] = {0},
    lancuch[MAXN] = {0},
    l[MAXN] = {0},
    c[MAXN] = {0};

void close_this(int value)
{
    printf("%d\n", value);
    exit(0);
}

void sprawdz(int kolor, int v)
{
    if (ile_powinno_byc[kolor] == ile_jest[kolor])
        ++ile_niezgodnych;
    ile_jest[kolor] += v;
    if (ile_powinno_byc[kolor] == ile_jest[kolor])
        --ile_niezgodnych;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> l[i];
        d += l[i];
        if (d > n)
        {
            close_this(0);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> c[i];
        --c[i];
    }
    for (int i = 0; i < m; ++i)
        ile_powinno_byc[c[i]] = l[i];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> lancuch[i];
        --lancuch[i];
    }

    ile_niezgodnych = m;
    for (int i = 0; i < d; ++i)
        sprawdz(lancuch[i], 1);
    if (ile_niezgodnych == 0)
        ++wynik;

    for (int i = 0; i + d < n; ++i)
    {
        sprawdz(lancuch[i], -1);
        sprawdz(lancuch[i + d], 1);
        if (ile_niezgodnych == 0)
            ++wynik;
    }
    close_this(wynik);
    return 0;
}