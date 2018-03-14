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
    int *klucze = new int[bsize]{0};

    for(int i = 1; i < bsize; ++i)
    {
        cin >> szef[i];
        cin >> pensja[i];
        klucze[pensja[i]] = i;
    }

    klucze[0] = 0;

    for(int i = 1; i < bsize; ++i)
    {
        if(szef[i] == i) pensja[i] = size;
        ++liczbaPodwladnych[szef[i]];
    }

    for(int i = 1; i < bsize; ++i)
    {
        if(liczbaPodwladnych[szef[i]] == 1)
        {
            if(pensja[szef[i]] != 0 && pensja[szef[i]] != size)
            {
                pensja[i] = pensja[szef[i]] - 1;
            }
            else if(pensja[i] != 0 && pensja[szef[i]] != size)
            {
                pensja[szef[i]] = pensja[i] + 1;
            }
        }
    }

    for(int i = 1; i < bsize; ++i)
    {
        printf("%d\n", pensja[i]);
    }
   
    return 0;
}