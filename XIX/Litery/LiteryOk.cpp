#include <iostream>
#include <vector>

using namespace std;

int NearestPowTwo(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        if((1 << i) > n) return i;
    }
    return 0;
}

void Insert(int index, int size, int Tree[])
{
    int x = size + index;

    Tree[x] = 1;

    for(;x > 1;)
    {
        x /= 2;
        Tree[x] = Tree[2 * x] + Tree[2 * x + 1];
    }
}

long CountReps(int left, int size, int Tree[])
{
    if(left >= size) return 0;
    int leftx = size + 1 + left;
    int rightx = 2 * size - 1;

    if(leftx == rightx) return Tree[leftx];
    
    int count = Tree[leftx] + Tree[rightx];

    for(;(leftx / 2) != (rightx / 2);)
    {
        if(leftx % 2 == 0) count += Tree[leftx + 1];
        if(rightx % 2 == 1) count += Tree[rightx - 1];
        
        leftx /= 2;
        rightx /= 2;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int size = 0;
    
    cin >> size;
    int Tsize = 1 << NearestPowTwo(size);
    
    char *Jas = new char[size];
    char *Malgosia = new char[size];
    
    cin >> Jas;
    cin >> Malgosia;
    
    int *Tree = new int[2 * Tsize] {0};

    vector <int> Letters[26];

    for(int i = size - 1; i >= 0; --i)
    {
        Jas[i] -= 65;
        
        Letters[int(Jas[i])].push_back(i); 
    }

    long long swaps = 0;

    int index = 0;
    for(int i = 0; i < size; ++i)
    {
        Malgosia[i] -= 65;
        index = Letters[int(Malgosia[i])].back();
       
        Letters[int(Malgosia[i])].pop_back();

        Insert(index, Tsize, Tree);
        
        index += CountReps(index, Tsize, Tree);
        swaps += index - i;
    }

    cout << swaps << "\n";

    delete[] Jas;
    delete[] Malgosia;
    delete[] Tree;

    return 0;
}