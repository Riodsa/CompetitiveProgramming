#include<bits/stdc++.h>
using namespace std;

set<pair<int,int>> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int opr; cin >> opr;
        if(opr == 1)
        {
            int a,b;
            cin >> a >> b;
            s.insert({a,b});
            auto now = s.find({a,b});
            auto prev = now,next = now;
            if(now != s.begin())
            {
                prev--;
                if(prev->second >= now->first-1)
                {
                    // cout << "erase\n";
                    a = prev->first;
                    b = max(now->second,prev->second);
                    s.erase(*now);
                    s.erase(*prev);
                    s.insert({a,b});
                    now = s.find({a,b});
                }
            }
            next = now;
            next++;
            while(now->second >= next->first-1 && next != s.end())
            {
                // cout << "erase\n";
                a = now->first;
                b = max(next->second,now->second);
                s.erase(*now);
                s.erase(*next);
                s.insert({a,b});
                now = s.find({a,b});
                next = now;
                next++;
            }
        }
        else if(opr == 2)
        {
            cout << s.size() << '\n';
        }
    }
    return 0;
}