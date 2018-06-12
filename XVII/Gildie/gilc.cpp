#include <iostream>

typedef struct
{
    int a = 0, b = 0;
} para;

void ustaw(char &a, char &b)
{
    if (a == 'N')
        b == 'K' ? a = 'S' : a = 'K';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n = 0, m = 0;

    std::cin >> n >> m;

    char *gildia = new char[n];
    bool *czy = new bool[n]{false};
    para *drogi = new para[m];
    int liczba = 0;

    for (int i = 0; i < n; ++i)
    {
        gildia[i] = 'N';
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> drogi[i].a;
        --drogi[i].a;
        std::cin >> drogi[i].b;
        --drogi[i].b;
        if (!czy[drogi[i].a])
        {
            ++liczba;
            czy[drogi[i].a] = true;
        }
        if (!czy[drogi[i].b])
        {
            ++liczba;
            czy[drogi[i].b] = true;
        }
    }
    if (liczba < n)
    {
        printf("NIE\n");
        return 0;
    }
    for (int i = 0; i < m; ++i)
    {
        ustaw(gildia[drogi[i].a], gildia[drogi[i].b]);
        ustaw(gildia[drogi[i].b], gildia[drogi[i].a]);
    }
    printf("TAK\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%c\n", gildia[i]);
    }
    return 0;
}