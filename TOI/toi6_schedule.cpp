#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+1;
int n,k,m;
bool can[N];
struct sig
{
    int value,status,idx;

    bool operator <(const sig &x)const{
        if(value != x.value) return value < x.value;
        return status < x.status;
    }

};

vector<sig> vec;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m;
    for(int i=1;i<=n;++i)
    {
        int u,v;
        cin >> u >> v;
        vec.push_back({u,1,i});
        vec.push_back({v+1,-1,i});
    }
    sort(vec.begin(),vec.end());
//    for(sig x : vec)
//    {
//        cout << x.value << " " << x.status << " " << x.idx << '\n';
//    }cout << '\n';
    int use = 0;
    for(sig x : vec)
    {
        int now = x.value;
        int idx = x.idx;
        int st = x.status;
        if(st == 1 && use < k)
        {
            ++use;
            can[idx] = true;
        }
        else if(st == -1)
        {
            if(can[idx]) --use;
        }
    }
    while(m--)
    {
        int chk;
        cin >> chk;
        (can[chk]) ? cout << "Y" : cout << "N", cout << " ";
    }
    return 0;
}

