#include <iostream>
const int maxm = 1000000;
int a[maxm];

bool test(int len, int m)
{
    bool flag = false;
    bool bflag = true;
    for (int i = 0, x = 0, k = 0; i < len; ++i)
    {
        std::cin >> x;
        flag = false;
        // printf("%d - start\n", k);
        // printf("%d - X\n", x);
        if (bflag)
        {
            for (; k < m && len - i <= m - k; ++k)
            {
                if (x == a[k])
                {
                    flag = true;
                    // printf("%d - break\n", k);
                    break;
                }
            }
            ++k;
            if (!flag)
                bflag = false;
        }
    }
    return flag;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int m = 0, n = 0;
    ;
    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a[i];
        // printf("%d ", a[i]);
    }
    // printf("\n");
    std::cin >> n;
    for (int i = 0, k = 0; i < n; ++i)
    {
        std::cin >> k;
        printf(test(k, m) ? "TAK\n" : "NIE\n");
    }
    return 0;
}