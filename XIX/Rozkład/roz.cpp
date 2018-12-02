#include <cstdio>
#include <cstdlib>
#define min(a, b) a < b ? a : b
typedef long long int LL;
const int MAXN = 87;
LL fib[MAXN];
int main()
{
    int tmp = 0;
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    scanf("%d", &tmp);
    while (--tmp)
    {
        LL N;
        int res = 0;
        scanf("%lld", &N);
        while (N > 0)
        {
            LL n = N;
            for (int i = 0; i < MAXN; ++i)
                n = min(n, std::abs(N - fib[i]));
            N = n;
            ++res;
        }
        printf("%d\n", res);
    }
    return 0;
}