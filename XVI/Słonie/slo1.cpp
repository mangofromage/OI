#include <iostream>
#define min(a, b) a < b ? a : b

typedef long long int LL;
const int MAXN = 1000000;

int oryg[MAXN] = {0},
    masa[MAXN] = {0},
    dcel[MAXN] = {0};

bool czy[MAXN] = {0};

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0,
        m_najlzejszego_slonia_w_ogole = 1 << 30;
    LL wynik = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> masa[i];
        m_najlzejszego_slonia_w_ogole = min(m_najlzejszego_slonia_w_ogole, masa[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> oryg[i];
        --oryg[i];
    }
    for (int i = 0, k = 0; i < n; ++i)
    {
        std::cin >> k;
        dcel[--k] = oryg[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (czy[i])
            continue;
        int k = i,
            m_najlzejszego_slonia_w_cyklu = 1 << 30,
            c = 0;
        LL suma = 0;

        do
        {
            suma += masa[k];
            m_najlzejszego_slonia_w_cyklu = min(m_najlzejszego_slonia_w_cyklu, masa[k]);
            k = dcel[k];
            czy[k] = 1;
            c++;
        } while (i != k);
        wynik += min(
            suma + (c - 2) * m_najlzejszego_slonia_w_cyklu,
            suma + m_najlzejszego_slonia_w_cyklu + (c + 1) * m_najlzejszego_slonia_w_ogole);
    }
    std::cout << wynik << '\n';
    return 0;
}