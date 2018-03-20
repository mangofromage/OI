#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int wys = 0;
    int n = 0;
    cin >> n;
    if(n == 0) return 0;

    int bez = 0;
    vector<int> s;
    int ile = 0;
    
    for(int i = 0; i < n; ++i)
    {
        cin >>bez;
        cin >> wys;
        for(;s.size() > 0 && s.back() > wys;)
        {
            s.pop_back();
        }
        if(s.size() == 0 || s.back() < wys)
        {
            s.push_back(wys);
            ++ile;
        }
    }

    cout << ile << endl;
    return 0;
}