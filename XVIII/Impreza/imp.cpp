#include <iostream>
#define MAXN 3000

bool para[MAXN][MAXN];
bool usuniety[MAXN];
int n, m, a, b;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
        para[a - 1][b - 1] = para[b - 1][a - 1] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int k = i + 1; k < n && !usuniety[i]; ++k)
        {
            if (!para[i][k] && !usuniety[k])
            {
                usuniety[i] = 1;
                usuniety[k] = 1;
            }
        }
    }
    int left = n / 3;
    for (int i = 0; left && i < n; ++i)
    {
        if (!usuniety[i])
        {
            --left;
            std::cout << i + 1 << " ";
        }
    }
    std::cout << '\n';
    return 0;
}