#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string country[n+1];
    int cost[n+1],total_cost = 0;
    for(int i=1;i<=n;++i) cin >> country[i] >> cost[i];
    string flight;
    getchar();
    getline(cin,flight);
    int len = flight.size();
    string tmp = "",c = "",recent = "";
    int cnt = 0;
    for(int i=0;i<=len;++i)
    {
        if(i != len && flight[i] != ' ') tmp += flight[i];
        else
        {
            c += tmp[tmp.size()-2];
            c += tmp[tmp.size()-1];
            for(int j=1;j<=n;++j)
            {
                if(cnt > 0 && c == country[j] && recent != c) total_cost += cost[j];
            }
            recent = c;
            // cout << c << ' ';
            tmp = "";
            c = "";
            ++cnt;
        }
    }
    // cout << '\n';
    cout << total_cost;
    return 0;
}   