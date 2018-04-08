#include <iostream>

using namespace std;

long long min(long long a, long long b)
{
  if(a < b) return a;
  return b;
}

int main()
{
  ios_base::sync_with_stdio(0);

  int n = 0;
  cin >> n;
  int miniSloniaWgl = 1 << 30;
  int *masa = new int[n];
  int *org = new int[n];
  int *cel = new int[n];
  bool *cykl = new bool[n]{0};

  for(int i = 0; i < n; ++i)
  {
    cin >> masa[i];
    miniSloniaWgl = min(miniSloniaWgl, masa[i]);
  }
  for(int i = 0; i < n; ++i)
  {
    cin >> org[i];
    --org[i];
  }
  for(int i = 0, k = 0; i < n; ++i)
  {
    cin >> k;
    cel[k - 1] = org[i];
  }
  long long wynik = 0;
  for(int i = 0; i < n; ++i)
  {
    if(!cykl[i])
    {
      long long suma = 0;
      int teraz = i;
      int miniteraz = 1 << 30;
      int ile = 0;
      do
      {
        miniteraz = min(miniteraz, masa[teraz]);
        suma += masa[teraz];
        teraz = cel[teraz];
        cykl[teraz] = true;
        ++ile;
      } while(teraz != i);
      wynik += min(suma + (ile - 2) * miniteraz, suma + miniteraz + (ile + 1) * miniSloniaWgl );
    }
  }
  cout << wynik << '\n';
  return 0;
}
