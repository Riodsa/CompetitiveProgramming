#include<iostream>
#include<climits>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int number[n+1],from[n+1],to[n+1];
    for(int i=1;i<=n;++i) cin >> number[i] >> from[i] >> to[i];
    int q;
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        int ans = INT_MAX,min_cost = INT_MAX;
        for(int i=1;i<=n;++i)
        {
            int cost = 0;
            if(a >= from[i] && a <= to[i])
            {
                if(b < from[i]) cost += to[i]-b;
                else if(b > to[i]) cost += b-to[i];
            }
            else if(a <= from[i] && a >= to[i])
            {
                if(b > from[i]) cost += b-to[i];
                else if(b < to[i]) cost += to[i]-b;
            }
            else cost += abs(to[i]-a) + abs(a-b);
            if(min_cost >= cost)
            {
                if(min_cost == cost)
                {
                    ans = min(ans,number[i]);
                }
                else
                {
                    min_cost = cost;
                    ans = number[i];
                }
            }
            // cout << "[" << number[i] << "] " << "cost = " << cost << '\n';
        }
        cout << ">> " << ans << '\n';
    }
    return 0;
}