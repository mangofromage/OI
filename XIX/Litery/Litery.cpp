#include "iostream"
#include "queue"

using namespace std;

void printLvl(int c, int val)
{
  for(int i = 0; i < c; ++i) printf(" ");
  printf("%d", val);
}

void PrintTree(int base, int tree[])
{
  int lvl = 1;
  int i = 1;
  int u = 1;
  while(lvl < 2 * base)
  {
    for(int k = 0; k < lvl; ++k)
    {
      int space = 0;
      if(k == 0) space = base / lvl - 1;
      else if(lvl > 0)
      {
        if(u % 2 == 0)
        {
          if(k % 2 == 0) space = (base / (lvl - 1));
          else space = (base / (lvl - 1)) - 1;
        }
        else
        {
          space = (base / (lvl - 1)) + 1;
        }
      }
      if(base == lvl && k == 0) space = 0;
      else if(base == lvl) space = 1;
      printLvl(space , tree[i]);
      ++i;
    }
    ++u;;
    lvl *= 2;
    printf("\n");
  }
}

int npow(int a)
{
  int i = 1;
  for(i = 1; i <=a; i <<=1);
  return i;
}

void insert(int index, int base, int tree[])
{
  int x = index + base;
  tree[x] = 1;
  while(x > 1)
  {
    x/=2;
    tree[x] = tree[2 * x] + tree[2 * x + 1];
  }
}

int query(int index, int base, int tree[])
{
  int lx = index + base + 1;
  int px = 2 * base - 1;
  if(lx == px) return tree[lx];
  if(lx > px) return 0;
  int count = tree[lx] + tree[px];
  while (lx / 2 != px / 2)
  {
    if(lx % 2 == 0) count += tree[lx + 1];
    if(px % 2 == 1) count += tree[px - 1];
    lx /= 2;
    px /= 2;
  }
  return count;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n = 0;
  cin >> n;

  char *jas = new char[n + 1];
  char *malgosia = new char[n + 1];
  int base = npow(n);
  int *tree = new int[2 * base];
  queue<int> litery[26];

  cin >> jas;
  cin >> malgosia;
  for(int i = 0; i < n; ++i)
  {
    jas[i] -= 65;
    litery[int(jas[i])].push(i);
  }

  long long wynik = 0;

  for(int i = 0, index; i < n; ++i)
  {
    malgosia[int(i)] -= 65;
    index = litery[int(malgosia[i])].front();
    insert(index, base, tree);
    litery[int(malgosia[i])].pop();
    wynik += index + query(index, base, tree) - i;
  }
  //PrintTree(base, tree);
  cout << wynik << '\n';
  return 0;
}
