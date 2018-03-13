#include <iostream>

typedef struct Pracownik Pracownik;

struct Pracownik
{
    int indexwlasny;
    int pensja;
    int indexszef;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int size = 0;
    
    std::cin >> size;

    if(size > 0)
    {
        Pracownik *Pracownicy = new Pracownik[size];

        for(int i = 0; i < size; ++i)
        {
            int pensja = 0;
            int indexszef = 0;
            std::cin >> Pracownicy[i].indexszef;
            std::cin >> Pracownicy[i].pensja;
        }
    }


    return 0;
}