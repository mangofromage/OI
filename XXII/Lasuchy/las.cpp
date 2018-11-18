#include <iostream>

void zamianka(int i, int n, int *tort, int *wyb)
{
    if (wyb[i] != i)
    {
        int l = i - 1 < 0 ? n - 1 : i - 1;
        int p = (i + 1) % n;
        int ilel = wyb[l] == l ? 1 : 2;
        int ilep = wyb[p] == p ? 2 : 1;
        double lt = double(tort[i]) / double(ilel);
        double pt = double(tort[p]) / double(ilep);
        // std::cout << lt << " " << pt << '\n';
        if (lt > pt)
        {
            wyb[i] = i;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0;
    std::cin >> n;
    int *tort = new int[n];
    int *wyb = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> tort[i];
        wyb[i] = (i + 1) % n;
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            zamianka(k, n, tort, wyb);
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        for (int k = n - 1; k >= 0; --k)
        {
            zamianka(k, n, tort, wyb);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << wyb[i] + 1 << ' ';
    }
    std::cout << '\n';
    return 0;
}