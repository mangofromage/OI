#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;

    int bsize = size + 1;

    int *szef = new int[bsize]{0};                  //kto jest szefem gościa o indeksie i
    int *liczbaPodwladnych = new int[bsize]{0};     //liczba podwladnych gościa o indeksie i
    int *pensja = new int[bsize]{0};                //pensja goscia o indeksie i
    int *klucze = new int[bsize]{0};
    int *dlugoscdrzewa = new int[bsize]{0};         //dlugosc drzewa zaczynającego się od gościa o indeksie i
    vector<int> podwladni[bsize];                   //tablica wektorów zawierająca dla każdego indeksu (czyli pracownika) indeksy jego podwladnych
    
    //wczytanie danych
    for(int i = 1; i < bsize; ++i)
    {
        cin >> szef[i];
        cin >> pensja[i];
        klucze[pensja[i]] = i;
    }

    klucze[0] = 0;

    //ustalenie liczby podwładnych
    for(int i = 1; i < bsize; ++i)
    {
        if(szef[i] == i) pensja[i] = size;
        ++liczbaPodwladnych[szef[i]];
    }

    //przypisanie szefom podwładnych
    for(int i = 1; i < bsize; ++i)
    {
        podwladni[szef[i]].push_back(i);
    }

    //pomocnycze wypisanie drzewa
    for(int i = 1; i < bsize; ++i)
    {
        //printf("rozmiar %d\n", podwladni[i].size());
        printf("%d: ", i);
        for(int k = 0;k < podwladni[i].size(); ++k)
        {
            printf("%d, ", podwladni[i].at(k));
        }
        printf("\n");
    }


    for(int i = 1; i < bsize; ++i)
    {
        printf("%d\n", pensja[i]);
    }
   
    return 0;
}