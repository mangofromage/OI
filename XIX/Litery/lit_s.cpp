#include <iostream>
#include <vector>
#include <string>
const int maxn = 10000000;
int tree[2 * maxn + 1],
    size = 0;

int npow(int a)
{
    int i = 1;
    for (; i <= a; i <<= 1)
        ;
    return i;
}

void insert(int index)
{
    int x = size + index;
    tree[x] = 1;
    while (x > 1)
    {
        x /= 2;
        tree[x] = tree[2 * x + 1] + tree[2 * x];
    }
}

int query(int index)
{
    int lx = size + index + 1;
    int px = 2 * size - 1;

    if (lx >= px)
        return 0;
    long long sum = tree[lx] + tree[px];
    while (lx / 2 != px / 2)
    {
        if (lx % 2 == 0)
            sum += tree[lx + 1];
        if (px % 2 == 1)
            sum += tree[px - 1];
        lx /= 2;
        px /= 2;
    }
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0;
    std::string jas = "", malgosia = "";
    std::vector<int> lit[26];
    std::cin >> n;
    size = npow(n);
    std::cin >> jas;
    std::cin >> malgosia;
    for (int i = n - 1; i >= 0; --i)
    {
        jas[i] -= 65;
        lit[int(jas[i])].push_back(i);
    }
    long long wynik = 0;
    for (int i = 0, k = 0; i < n; ++i)
    {
        malgosia[i] -= 65;
        k = lit[int(malgosia[i])].back();
        insert(k);
        lit[int(malgosia[i])].pop_back();
        wynik += k + query(k) - i;
    }
    std::cout << wynik << '\n';
    return 0;
}