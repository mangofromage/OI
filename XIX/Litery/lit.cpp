#include <iostream>
#include <queue>

class tree
{
    int base;
    int *tree_;

  public:
    static int npow(int);
    tree(int);
    void insert(int);
    int query(int);
};
int tree::npow(int a)
{
    int i = 1;
    for (i = 1; i <= a; i <<= 1)
        ;
    return i;
}

tree::tree(int a)
{
    base = npow(a);
    tree_ = new int[2 * base]{0};
}

void tree::insert(int index)
{
    int x = index + base;
    tree_[x] = 1;
    while (x > 1)
    {
        x /= 2;
        tree_[x] = tree_[2 * x] + tree_[2 * x + 1];
    }
}

int tree::query(int index)
{
    int lx = base + index + 1;
    int rx = 2 * base - 1;
    if (lx >= rx)
        return 0;
    int sum = tree_[lx] + tree_[rx];
    while (lx / 2 != rx / 2)
    {
        if (lx % 2 == 0)
            sum += tree_[lx + 1];
        if (rx % 2 == 1)
            sum += tree_[rx - 1];
        lx /= 2;
        rx /= 2;
    }
    // printf("%d\n", sum);
    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0;
    std::cin >> n;
    char *malgosia = new char[n + 1];
    char *jas = new char[n + 1];
    tree t(n);
    std::queue<int> lit[26];
    std::cin >> jas;
    std::cin >> malgosia;
    for (int i = 0; i < n; ++i)
    {
        jas[i] -= 65;
        lit[(int)jas[i]].push(i);
    }
    long long int wynik = 0;
    for (int i = 0, k = 0; i < n; ++i)
    {
        malgosia[i] -= 65;
        k = lit[(int)malgosia[i]].front();
        t.insert(k);
        lit[(int)malgosia[i]].pop();
        wynik += t.query(k) + k - i;
    }
    std::cout << wynik << '\n';
    return 0;
}