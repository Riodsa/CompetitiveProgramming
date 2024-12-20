#include<bits/stdc++.h>
using namespace std;

int n,w,l;

void solve(int cntw,int cntl,string stat)
{
    if(cntw == n || cntl == n)
    {
        for(char c : stat) cout << c << " ";
        cout << '\n';
        return ;
    }
    stat.push_back('W');
    solve(cntw+1,cntl,stat);
    stat.pop_back();
    stat.push_back('L');
    solve(cntw,cntl+1,stat);
    return ;
}

int main()
{
    cin >> n >> w >> l;
    string s = "";
    solve(w,l,s);
    return 0;
}
