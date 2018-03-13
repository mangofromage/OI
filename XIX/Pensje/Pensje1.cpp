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

void WywalPowtorzenia(vector<Pracownik> wektro)
{
    for(int i = 0, ostatni = 0; i < wektro.size(); ++i)
    {
        if(wektro[i].indexszef == ostatni) wektro.pop_back();
    }
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

        vector<Pracownik> Vpracownicy;

        for(int i = 0; i < size; ++i)
        {
            int pensja = 0;
            int indexszef = 0;
            cin >> Pracownicy[i].indexszef;
            cin >> Pracownicy[i].pensja;
            Pracownicy[i].indexwlasny = i;

            Vpracownicy.push_back(Pracownicy[i]);
        }

        sort(Vpracownicy.begin(), Vpracownicy.end(), porownajPracownikowSzef);

        for(int i = 0; i < size; ++i)
        {
            printf("%d, %d, %d\n", Vpracownicy[i].indexwlasny, Vpracownicy[i].indexszef, Vpracownicy[i].pensja);
        }

        printf("\n");
        for(int i = 0; i < size; ++i)
        {
            printf("%d, %d, %d\n", Pracownicy[i].indexwlasny, Pracownicy[i].indexszef, Pracownicy[i].pensja);
        }
    }


    return 0;
}