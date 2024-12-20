#include <bits/stdc++.h>
using namespace std;

int n, m, k, w;
vector<int> pos;
unordered_map<int, int> hp;
int sum_hp = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> w;
    pos.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> pos[i];
    for (int i = 0; i < m; ++i)
    {
        int health;
        cin >> health;
        sum_hp += health;
        hp[pos[i]] = health;
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < k; ++i)
    {
        int tower;
        cin >> tower;
        auto idx = lower_bound(pos.begin(), pos.end(), tower - w);
        if (idx != pos.end())
        {
            while (idx != pos.end() && *idx <= tower + w)
            {
                if (hp[*idx] != 0)
                {
                    hp[*idx]--;
                    sum_hp--;
                    break;
                }
                ++idx;
            }
        }
    }
    cout << sum_hp;
    return 0;
}