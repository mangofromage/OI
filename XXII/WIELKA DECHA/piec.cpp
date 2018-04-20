#include "iostream"
using namespace std;

typedef long long int LL;

int max(int a, int b)
{
  if(a > b) return a;
  return b;
}

int getSum(int l, int p, LL v[])
{
  if(l == 0) return v[p];
  return v[p] - v[l - 1];
}

int getmMaxv(int l, int p, LL v[])
{
  LL mx = 0;
  for(; l < p; ++l)
  {
    if(v[l] > mx) mx = v[l];
  }
  return mx;
}

int main()
{
  ios_base::sync_with_stdio(0);
  LL n, p, d;
  cin >> n >> p >> d;
  if(n == d)
  {
    cout << n << '\n';
    return 0;
  }
  LL *suma = new LL[n];
  LL *maxD = new LL[n];
  LL b = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> b;
    if(i == 0) suma[0] = b;
    else suma[i] = suma[i - 1] + b;
    //if(suma[i] <= 0) cout << suma[i] << " suma\n";
  }

  for(int i = 0; i < n - d + 2; ++i)
  {
    if(i == 0) maxD[0] = suma[d - 1];
    else maxD[i] = suma[i + d - 1] - suma[i - 1];
    //cout << maxD[i] << endl;
    //if(maxD[i] <= 0) cout << maxD[i] << " maxD\n";
  }

  LL wynik = d;
  LL j = d;
  for(int i = 0; i < n - d; ++i)
  {
    j = max(j, i + d - 1);
    while(j < n && getSum(i, j, suma) - getmMaxv(i, j - d + 2, maxD) <= p)
    {
      ++j;
    }
    wynik = max(wynik, j - i + 1);
  }
  cout << wynik - 1 << '\n';
  return 0;
}
