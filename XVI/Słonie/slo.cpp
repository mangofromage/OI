#include <iostream>
#define min(a, b) a < b ? a : b

const int MAXN = 1000002;
int oryg[MAXN], masa[MAXN], cel[MAXN];
bool czy[MAXN] = {0};

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0,
        minwgl = 1 << 30;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> masa[i];
        minwgl = min(minwgl, masa[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> oryg[i];
        --oryg[i];
    }
    for (int i = 0, k = 0; i < n; ++i)
    {
        std::cin >> k;
        cel[k - 1] = oryg[i];
    }
    long long wynik = 0;
    for (int i = 0; i < n; ++i)
    {
        if (czy[i])
            continue;

        long long sum = 0;
        int mintera = 1 << 30,
            c = 0,
            d = i;

        do
        {
            sum += masa[d];
            mintera = min(mintera, masa[d]);
            d = cel[d];
            czy[d] = true;
            ++c;
        } while (d != i);
        wynik += min(sum + (c - 2) * mintera, sum + (c + 1) * minwgl + mintera);
    }
    std::cout << wynik << '\n';
    return 0;
}