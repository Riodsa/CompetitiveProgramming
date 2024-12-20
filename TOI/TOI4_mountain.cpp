#include<bits/stdc++.h>
using namespace std;

char b[15][100];
int max_hei[100];
int cnt_up[15][100],cnt_down[15][100];
int max_h,max_s;
vector<pair<int,int> > point;

void paint_down(int start,int height)
{
    int cnt = 1;
    for(int i=height;i>=1;--i)
    {
        if(b[i][start] == '.') b[i][start] = '\\';
        cnt_down[i][start]++;
        ++start;
        max_hei[start] = max(max_hei[start],i);
    }
}

void paint_up(int start,int height)
{
    int cnt = 1;
    int last;
    for(int i=cnt;i<=height;++i)
    {
        if(b[i][start] == '.') b[i][start] = '/';
        cnt_up[i][start]++;
        ++start;
        last = i;
        max_hei[start] = max(max_hei[start],i);
    }
    paint_down(start,last);
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int s,h;
        cin >> s >> h;
        point.emplace_back(s,h);
        max_h = max(max_h,h);
        max_s = max(max_s,s+2*h-1);
    }
    for(int i=max_h;i>=1;i--)
    {
        for(int j=1;j<=max_s;++j)
        {
            b[i][j] = '.';
        }
    }
    for(auto x : point)
    {
        int start,hei;
        tie(start,hei) = x;
        paint_up(start,hei);
    }
//    cout << "max_s " << max_s << " max_h" << max_h << '\n';
    for(int j=1;j<=max_s;++j)
    {
        for(int i=max_hei[j]-1;i>=1;--i)
        {
            b[i][j-1] = 'X';
        }
    }
    for(int i=max_h;i>=1;i--)
    {
        for(int j=1;j<=max_s;++j)
        {
            if(cnt_up[i][j] > 0 && cnt_down[i][j] > 0) cout << "v";
            else cout << b[i][j];
        }
        cout << '\n';
    }
//    for(int i=1;i<=max_s;++i) cout << max_hei[i] << " ";
    return 0;
}
