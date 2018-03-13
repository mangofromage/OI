#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Pracownik Pracownik;

struct Pracownik
{
    int indexwlasny;
    int pensja;
    int indexszef;
};

bool porownajPracownikowSzef(const Pracownik &a, const Pracownik &b)
{
    return a.indexszef < b.indexszef; 
}

vector<Pracownik> liczpow(vector<Pracownik> wektro)
{
    
    for(int i = 0, ostatni = 0; i < wektro.size(); ++i)
    {
        if(wektro[i].indexszef == ostatni) wektro.erase(wektro.begin() + i);
        ostatni = wektro[i].indexszef;
    }
}

bool CzySzef(Pracownik p)
{
    return p.indexwlasny == p.indexszef;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size = 0;
    
    cin >> size;

    if(size > 0)
    {
        Pracownik *Pracownicy = new Pracownik[size];
        int *Pensje = new int[size];

        vector<Pracownik> Vpracownicy;

        for(int i = 0; i < size; ++i)
        {
            int pensja = 0;
            int indexszef = 0;
            cin >> Pracownicy[i].indexszef;
            //--Pracownicy[i].indexszef;
            cin >> Pracownicy[i].pensja;
            Pensje[i] = Pracownicy[i].pensja;
            Pracownicy[i].indexwlasny = i + 1;
            //printf("%d, %d\n", Pracownicy[i].indexwlasny, Pracownicy[i].indexszef);
            //int y = Pracownicy[i].indexwlasny - Pracownicy[i].indexszef;
            //printf("y = %d\nsize = %d\n", y, size);
            //if(y == 0) Pensje[i] = size;
            if(CzySzef(Pracownicy[i])) Pensje[i] = size;
            Vpracownicy.push_back(Pracownicy[i]);
        }

        sort(Vpracownicy.begin(), Vpracownicy.end(), porownajPracownikowSzef);

        //for(int i = 0; i < Vpracownicy.size(); ++i)
        //{
        //    printf("%d, %d, %d\n", Vpracownicy[i].indexwlasny, Vpracownicy[i].indexszef, Vpracownicy[i].pensja);
        //}

        //printf("\n");
        //for(int i = 0; i < size; ++i)
        //{
        //    printf("%d, %d, %d\n", Pracownicy[i].indexwlasny, Pracownicy[i].indexszef, Pracownicy[i].pensja);
        //}

        bool *czy = new bool[size]{false}; 
        for(int i = 0, ostatni = 0, flag = 0; i < Vpracownicy.size(); ++i)
        {
            if(ostatni == Vpracownicy[i].indexszef && Vpracownicy[i].pensja == 0)
            {
                czy[i] = true;
                if(flag == 0) 
                {
                    czy[i - 1] = true;
                    flag = 1;
                }
            }
            else flag = 0;
            ostatni = Vpracownicy[i].indexszef;
        }

        vector<Pracownik> v;

        for(int i = 0; i < Vpracownicy.size(); ++i)
        {
            if(!czy[i]) v.push_back(Vpracownicy[i]);
        }

        //printf("\n");
        //for(int i = 0; i < v.size(); ++i)
        //{
         //   printf("%d, %d, %d\n", v[i].indexwlasny, v[i].indexszef, v[i].pensja);
        //}

        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i].pensja == 0)
            {
                if(Pensje[v[i].indexszef - 1] != 0 && !CzySzef(v[i])) Pensje[v[i].indexwlasny - 1] = Pensje[v[i].indexszef - 1]-1;
            }
            else
            {
                if(Pensje[v[i].indexszef - 1] == 0) Pensje[v[i].indexszef - 1] = Pensje[v[i].indexwlasny - 1] + 1;
            }
        }
        //printf("\n");
        for(int i = 0; i < size; ++i)
        {
            printf("%d\n", Pensje[i]);
        }
    }

    return 0;
}