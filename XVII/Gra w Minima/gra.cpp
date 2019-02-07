#include <iostream>
#include <vector>
#include <algorithm>
#define max(a, b) a > b ? a : b

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0;
    std::cin >> n;
    int wynik = 0;
    std::vector<int> karta;
    for (int i = 0, k; i < n; ++i)
    {
        std::cin >> k;
        karta.push_back(k);
    }
    std::sort(karta.begin(), karta.end());
    wynik = karta[0];
    for(int i = 1; i < n; ++i)
    {
        wynik = max(karta[i] - wynik, wynik);
    }
    printf("%d\n", wynik);
    return 0;
}
