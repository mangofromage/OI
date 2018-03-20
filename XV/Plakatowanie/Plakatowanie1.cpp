#include <iostream>
#include <vector>
using namespace std;

int wys[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    if(n == 0) return 0;

    int bez = 0;
    vector<int> s;
    int ile = 0;
    
    for(int i = 0; i < n; ++i)
    {
        cin >>bez;
        cin >> wys[i];
        for(;s.size() > 0 && s.back() > wys[i];)
        {
            s.pop_back();
        }
        if(s.size() == 0 || s.back() < wys[i])
        {
            s.push_back(wys[i]);
            ++ile;
        }
    }

    cout << ile << endl;
    return 0;
}