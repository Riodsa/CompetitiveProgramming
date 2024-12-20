#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> s;
    int x;
    int cnt = 1;
    bool found = false;
    while(cin >> x)
    {
        // if(x == -1) break;
        if(s.find(x) != s.end())
        {
            found = true;
            break;
        }
        s.insert(x);
        ++cnt;
    }
    if(found) cout << cnt;
    else cout << "-1";
    return 0;
}