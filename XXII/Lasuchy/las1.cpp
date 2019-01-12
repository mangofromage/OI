#include <iostream>

const int MAXN = 1000000;
int c[MAXN] = {0},
    wyb[MAXN] = {0};

void zamianka(int i, int n)
{
    if (wyb[i] == i)
        return;
    int li = i - 1 < 0 ? n - 1 : i - 1,
        pi = (i + 1) % n,
        wlc = wyb[li] == i ? 2 : 1,
        wpc = wyb[pi] == pi ? 2 : 1;
    double lkcal = (double)c[i],
           pkcal = (double)c[pi],
           lopt = lkcal / (double)wlc,
           popt = pkcal / (double)wpc;
    if (lopt > popt)
        wyb[i] = i;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c[i];
        wyb[i] = (i + 1) % n;
    }

    for (int k = 0; k < 2; ++k)
        for (int i = 0; i < n; ++i)
        {
            zamianka(i, n);
        }
    for (int k = 0; k < 2; ++k)
        for (int i = n - 1; i >= 0; --i)
        {
            zamianka(i, n);
        }
    for (int i = 0; i < n; ++i)
        printf("%d ", wyb[i] + 1);
    printf("\n");
    return 0;
}