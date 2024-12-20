#include<bits/stdc++.h>
using namespace std;

int n;

void go(int floor,string tower)
{
    if(floor == n)
    {
        cout << tower << "E\n";
        return ;
    }
    if(floor+1 <= n) go(floor+1,tower+"--\n");
    if(floor+2 <= n) go(floor+2,tower+"||\n");
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    string s = "";
    go(0,s);
    return 0;
}
