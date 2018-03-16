#include <iostream>
#include <vector>

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

    for(int i = 1; i < bsize; ++i)
    {
        //printf("%d\n", pensja[i]);
    }
   
    return 0;
}