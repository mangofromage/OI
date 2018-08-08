#include <iostream>
#include <algorithm>
#define max(a, b) a > b ? a : b

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0;
    std::cin >> n;
    int *in = new int[n];
    int wynik = 0;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> in[i];
        wynik += in[i];
    }
    std::sort(in, in + n);
    for(int i = 0; i < (n + 1) / 2; ++i)
    {
        wynik -= in[i];
    }
    for(int i = n % 2 == 0 ? (n + 1) / 2 : (n + 1) / 2 - 1; i < n; ++i)
    {
        wynik += in[i];
    }
    std::cout << wynik << '\n';
    return 0;
}