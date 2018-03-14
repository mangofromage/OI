#include <iostream>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;

    int bsize = size + 1;

    int *szef = new int[bsize]{0};
    int *liczbaPodwladnych = new int[bsize]{0};
    int *pensja = new int[bsize]{0};

    for(int i = 1; i < bsize; ++i)
    {
        cin >> szef[i];
        cin >> pensja[i];
    }

    for(int i = 1; i < bsize; ++i)
    {
        if(szef[i] == i) pensja[i] = size;
        ++liczbaPodwladnych[szef[i]];
    }
   
    return 0;
}