#include<bits/stdc++.h>
using namespace std;

string ch[5][5];

int n;
stack<char> ans;

int main()
{
    ch[1][1] = "DEL";
    ch[1][2] = "ABC";
    ch[1][3] = "DEF";
    ch[2][1] = "GHI";
    ch[2][2] = "JKL";
    ch[2][3] = "MNO";
    ch[3][1] = "PQRS";
    ch[3][2] = "TUV";
    ch[3][3] = "WXYZ";
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int start,cnt;
    cin >> start >> cnt;
    int x,y;
    if(start <= 3) y = 1;
    else if(start <= 6) y = 2;
    else if(start <= 9) y = 3;
    if(start%3 == 1) x = 1;
    else if(start%3 == 2) x = 2;
    else if(start%3 == 0) x = 3;
    if(x==1&&y==1)
    {
        while(cnt--) if(!ans.empty()) ans.pop();
    }
    else ans.push(ch[y][x][(cnt-1)%ch[y][x].length()]);
//    cout << "x = " << x << " y = " << y << " cnt = " << cnt << " ans = " << ans << '\n';
    for(int i=1;i<=n-1;++i)
    {
        int h,v,c;
        cin >> h >> v >> c;
        x += h;
        y += v;
        if(x==1&&y==1)
        {
            while(c--) if(!ans.empty()) ans.pop();
        }
        else ans.push(ch[y][x][(c-1)%ch[y][x].length()]);
//        cout << "x = " << x << " y = " << y << " cnt = " << c << " ans = " << ans << '\n';
    }
    string str = "";
    if(ans.empty()) cout << "null";
    else
    {
        while(!ans.empty())
        {
            str += ans.top();
            ans.pop();
        }
    }
    reverse(str.begin(),str.end());
    cout << str;
    return 0;
}
