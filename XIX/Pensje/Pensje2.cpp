#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DlugoscDrzewa(vector<int> *podwladni, int indeks)
{
    int liczba = 1;
    //printf("Test %d\n", indeks);
    for(int i = 0; i < podwladni[indeks].size(); ++i)
    {
        if(podwladni[indeks].at(i) != indeks) liczba += DlugoscDrzewa(podwladni, podwladni[indeks].at(i));
    }
    return liczba;
}

void UstawKlucze(vector<int> klucze, int indeks, int *pensje, vector<int> *podwladni)
{
    if(pensje[indeks] == 0) pensje[indeks] = klucze.back();
    klucze.pop_back();
    if(podwladni[indeks].size() == 1) UstawKlucze(klucze, podwladni[indeks].back(), pensje, podwladni);
}

void WezKilkaKluczy(vector<int> a, vector<int> *b, int n)    //wpisuje do b n kluczy z a
{
    printf("TT\n");
    if(a.size() >= n)
    {
        //printf("TU\n");
        for(int i = 0; i < n; ++i)
        {
            int k = a.at(i);
            (*b).push_back(k);
        }
        //printf("TU rozmiar: %d\n", (*b).size());
    }
} 

void WezKilkaKluczy(int *a, vector<int> *b, int n)    //wpisuje do b n kluczy z a
{
    printf("TT\n");
    //printf("TU\n");
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == 0) (*b).push_back(a[i]);
        else ++n;
    }
    //printf("TU rozmiar: %d\n", (*b).size());
    
} 

int main()
{
    int size = 0;
    int indeksSzefa = 0;
    cin >> size;

    int bsize = size + 1;

    int *szef = new int[bsize]{0};                  //kto jest szefem gościa o indeksie i
    int *liczbaPodwladnych = new int[bsize]{0};     //liczba podwladnych gościa o indeksie i
    int *pensja = new int[bsize]{0};                //pensja goscia o indeksie i
    int *klucze = new int[bsize]{0};                //klucze[kwota] = {jeżeli wolny: 0}, {jeżeli należy do kogoś: indeks}, {jeżeli nie może być użyty: -1}
    int *dlugoscdrzewa = new int[bsize]{0};         //dlugosc drzewa zaczynającego się od gościa o indeksie i
    //vector<int> podwladni[bsize];                   //tablica wektorów zawierająca dla każdego indeksu (czyli pracownika) indeksy jego podwladnych
    vector<int> *podwladni = new vector<int>[bsize];
    vector<int> wolne;

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
        if(szef[i] == i) 
        {
            pensja[i] = size;
            indeksSzefa = i;
        }
        ++liczbaPodwladnych[szef[i]];

        if(klucze[i] == 0) wolne.push_back(i);
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

    printf("Dlugosc drzewa od 2: %d\n", DlugoscDrzewa(podwladni, 4));

    sort(wolne.begin(), wolne.end());
    for(int i = 1; i < bsize; ++i)
    {
        if(pensja[i] != 0)
        {
            //printf("T\n");
            int rozmiar = DlugoscDrzewa(podwladni, i);
            if(wolne.size() > i)
            {
                //printf("U\n");
                vector<int> *b = new vector<int>;
                WezKilkaKluczy(klucze, b, rozmiar);
                if(wolne.size() > rozmiar)
                {
                    printf("W\n");
                    if(wolne.at(rozmiar) >= pensja[i])
                    {
                        //printf("X\nRozmiar b: %d\n", (*b).size());
                        if((*b).size() >= rozmiar)
                        {
                            printf("Y\n");
                            //if(pensja[i] <= (*b).back()) (*b).pop_back();

                            UstawKlucze(*b, i, pensja, podwladni);
                        }
                    }
                }

                for(int i = 1; i < rozmiar - 1; ++i) 
                {
                    klucze[i] = -1;
                    if(wolne.size() > 0) wolne.pop_back();
                }
            }
        }
    }

    for(int i = 1; i < bsize; ++i)
    {
        printf("%d\n", pensja[i]);
    }
   
    return 0;
}