#include "iostream"
using namespace std;

typedef long long int LL;

LL lenght = 0;

class intervalTree
{
  LL *tree;
  int base;
public:
  intervalTree(int);
  void insert(int, int);
  LL query(int, int);
};

intervalTree::intervalTree(int n)
{
  int y = 1;
  for(y = 1; y <=n; y <<= 1);
  base = y;
  tree = new LL[2 * base];
}

void intervalTree::insert(int x, int value)
{
  int index = x + base;
  tree[index] = value;
  while(index > 1)
  {
    index /= 2;
    tree[index] = tree[2 * index] + tree[2 * index + 1];
  }
}

LL intervalTree::query(int a, int b)
{
  int lx = a + base;
  int px = b + base;
  if(px >= 2 * base) return 0;
  if(px == lx) return tree[lx];
  LL count = tree[lx] + tree[px];
  while(lx / 2 != px / 2)
  {
    if(lx % 2 == 0) count += tree[lx + 1];
    if(px % 2 == 1) count += tree[px - 1];
    lx /= 2;
    px /= 2;
  }
  return count;
}


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
  //++lenght;
  return mx;
}

LL getMaxx(int index, LL v[])
{
  ++lenght;
  return v[index];
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
  LL lj = j;
  LL maxInv = maxD[0];
  int Lindex = 0;
  for(int i = 0; i < n - d; ++i)
  {
    lj = j;
    j = max(j, i + d - 1);

    for(int k = lj; k < j; ++k)
    {
      if(maxD[k] > maxInv || i > Lindex)
      {
        maxInv = getMaxx(k - d + 1, maxD);
        Lindex = k - d + 1;
      }
    }

    while(j < n && getSum(i, j, suma) - maxInv <= p)
    {
      ++j;
    }
    wynik = max(wynik, j - i + 1);
  }
  cout << wynik << '\n';
  cout << "L " << lenght << '\n';
  return 0;
}
