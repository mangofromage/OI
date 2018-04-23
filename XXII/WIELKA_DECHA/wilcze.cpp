#include <iostream>
using namespace std;

typedef unsigned long long int LL;

LL lenght = 0;

LL max(LL a, LL b)
{
    if (a > b)
        return a;
    return b;
}

LL getSum(int l, int p, LL v[])
{
    if (l == 0)
        return v[p];
    return v[p] - v[l - 1];
}

LL getmMaxv(int l, int p, LL v[])
{
    LL mx = 0;
    for (; l < p; ++l)
    {
        if (v[l] > mx)
            mx = v[l];
    }
    ++lenght;
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    LL n, p, d;
    cin >> n >> p >> d;
    if (n == d)
    {
        cout << n << '\n';
        return 0;
    }

    LL *suma = new LL[n];
    LL *maxD = new LL[n];
    LL b = 0;
    for (LL i = 0; i < n; ++i)
    {
        cin >> b;
        if (i == 0)
            suma[0] = b;
        else
            suma[i] = suma[i - 1] + b;
    }

    for (LL i = 0; i < n - d + 2; ++i)
    {
        if (i == 0)
            maxD[0] = suma[d - 1];
        else
            maxD[i] = suma[i + d - 1] - suma[i - 1];
    }

    LL wynik = d;
    LL j = d;
    LL MAXDH = maxD[0];
    LL lj = 0;
    
    for (LL i = 0, li = 0; i < n - d + 2; ++i)
    {
        j = max(j, i + d - 1);

        if (maxD[li] == MAXDH)
        {
            if (maxD[i] >= MAXDH)
            {
                MAXDH = maxD[i];
            }
            else
            {
                MAXDH = getmMaxv(i, j - d + 2, maxD);
            }
        }
        else if (lj != j)
        {
            MAXDH = max(MAXDH, getmMaxv(lj, j - d + 2, maxD));
        }

        while (j < n && getSum(i, j, suma) - MAXDH <= p)
        {
            ++j;
            if (maxD[j - d + 1] >= MAXDH)
                MAXDH = maxD[j - d + 1];
        }
        wynik = max(wynik, j - i + 1);
        li = i;
        lj = j;
    }
    cout << wynik - 1 << '\n';
    //cout << "L " << lenght << '\n';
    return 0;
}
