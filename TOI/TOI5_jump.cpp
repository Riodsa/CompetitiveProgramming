#include<bits/stdc++.h>
using namespace std;

vector<int> line;
int n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin >> x;
        line.push_back(x);
    }
    int max_jump = -1;
    for(int i=0;i<n;++i)
    {
        auto pos = upper_bound(line.begin(),line.end(),line[i]+k)-line.begin();
        int jump = pos-i-1;
        max_jump = max(max_jump,jump);
    }
    cout << max_jump;
    return 0;
}
