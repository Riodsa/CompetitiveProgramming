#include<bits/stdc++.h>
using namespace std;

int n;

void solve(string s,int cnt)
{
    if(cnt == n)
    {
        for(int i=n-1;i>=0;--i)
        {
            string tmp = s;
            if(s[i] == '0') tmp[i] = '1';
            else continue;

            cout << s << " " << tmp << '\n';
        }
        return ;
    }
    else
    {
        solve(s+'0',cnt+1);
        solve(s+'1',cnt+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    solve("",0);
    return 0;
}
