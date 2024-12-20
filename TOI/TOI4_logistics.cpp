#include<bits/stdc++.h>
using namespace std;

const int N = 275;
#define ccd tuple<char,char,double>
#define pcd pair<char,double>
map<char,vector<pcd>> mp;
bool found = false;
vector<ccd> ans;
bool vis[N];

void dfs(char u,char par)
{
    vis[u] = true;
    if(u == 'Y')
    {
        found = true;
        return ;
    }
    vector<double> w;
    char v;
    char vv;
    double dis;
//    cout << "from " << u << '\n';
    bool last = true;
    for(pcd x : mp[u])
    {
        tie(v,dis) = x;
        if(v == par || vis[v]) continue;
        vv = v;
        last = false;
        if(vv == 'Y') found = true;
//        cout << "to " << vv << " use " << dis << '\n';
        w.push_back(dis);
    }
    if(w.empty()) return ;
    sort(w.begin(),w.end());
    int n = w.size();
//    cout << "w : ";
//    for(int x : w )
//    {
//        cout << x << " ";
//    }
//    cout << '\n';
    double d = (n%2==1) ? (w[(n/2)]) : ((w[n/2]+w[(n/2)-1])/2.0);
    ans.push_back({u,vv,d});
    if(!last) dfs(vv,u);
    else return ;
}

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        char a,b;
        double x;
        cin >> a >> b >> x;
        mp[a].push_back({b,x});
        mp[b].push_back({a,x});
    }
    dfs('X','A');
    if(found)
    {
        double sum = 0;
        for(ccd x : ans)
        {
            char u,v;
            double w;
            tie(u,v,w) = x;
            sum += w;
            cout << u << " " << v << " ";
            printf("%.1lf\n",w);
        }
        printf("%.1lf",sum);
    }
    else cout << "broken";
    return 0;
}
