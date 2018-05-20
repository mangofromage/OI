#include <iostream>
typedef long long int Lint;

Lint range(Lint a, Lint b)
{
    if (a < 0)
        return b - 1;
    if (a >= b)
        return 0;
    return a;
}

double kcal(double a, double b)
{
    if (b > 1)
        return a / b;
    return a;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    Lint n = 0;
    std::cin >> n;
    Lint *tort = new Lint[n];
    Lint *lasuch = new Lint[n];
    Lint *ilu = new Lint[n];
    for (Lint i = 0; i < n; ++i)
    {
        std::cin >> tort[i];
        lasuch[i] = i + 1;
        ilu[i] = 1;
    }
    lasuch[n - 1] = 0;
    for (char c = 0; c < 3; ++c)
    {
        for (Lint i = 0, m = 1; i < n; ++i, m = range(i + 1, n))
        {
            if (lasuch[i] == m)
            {
                if (kcal(tort[i], ilu[i] + 1.0) > kcal(tort[m], ilu[m]))
                {
                    --ilu[lasuch[i]];
                    lasuch[i] = i;
                    ++ilu[lasuch[i]];
                }
            }
        }
    }
    for (char c = 0; c < 3; ++c)
    {
        for (Lint i = n - 1, m = 0; i >= 0; --i, m = range(i + 1, n))
        {
            if (lasuch[i] == m)
            {
                if (kcal(tort[i], ilu[i] + 1.0) > kcal(tort[m], ilu[m]))
                {
                    --ilu[lasuch[i]];
                    lasuch[i] = i;
                    ++ilu[lasuch[i]];
                }
            }
        }
    }
    for (Lint i = 0; i < n; ++i)
    {
        std::cout << ++lasuch[i] << " ";
    }
    std::cout << '\n';
    return 0;
}