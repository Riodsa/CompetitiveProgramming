#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    int x1[n+1],y1[n+1],x2[n+1],y2[n+1];
    int max_overlapping = -1;
    for(int i=1;i<=n;++i) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int overlapping = 0;
            int xx = min(x2[i],x2[j])-max(x1[i],x1[j]);
            int yy = min(y2[i],y2[j])-max(y1[i],y1[j]);
            if(xx > 0 && yy > 0) overlapping = xx*yy;
            if(overlapping > max_overlapping)
            {
                max_overlapping = overlapping;
                ans.clear();
                ans.push_back({i,j});
            }
            else if(overlapping == max_overlapping) ans.push_back({i,j});
        }
        // cout << '\n';
    }
    if(max_overlapping != 0)
    {
        cout << "Max overlapping area = " << max_overlapping << '\n';
        for(pair<int,int> x : ans)
        {
            cout << "rectangles " << x.first-1 << " and " << x.second-1 << '\n';
        }
    }
    else cout << "No overlaps";
    return 0;
}