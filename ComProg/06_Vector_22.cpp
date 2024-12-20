#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int mxsz = -1;
    string s;
    getline(cin,s);
    int len = s.size();
    vector<int> num;
    for(int i=0;i<len;++i)
    {
        if(s[i] == ' ') continue;
        num.push_back(s[i]-'0');
    }
    // for(int a : num) cout << a << ' ';
    vector<tuple<int,int,int>> dup;
    int cb = 1;
    int l = num.size();
    for(int i=0;i<=l;++i)
    {
        // cout << num[i-1] << ' ' << num[i] << '\n';
        if(i-1 >= 0 && num[i-1] == num[i] && i != l) ++cb;
        else
        {
            if(cb == mxsz)
            {
                dup.emplace_back(num[i-1],i-mxsz,i);
            }
            cb = 1;
        }
        if(mxsz < cb)
        {
            mxsz = cb;
            dup.clear();
        }
    }
    sort(dup.begin(),dup.end());
    // cout << "max_size = " << mxsz << '\n';
    for(auto a : dup)
    {
        int x,y,z;
        tie(x,y,z) = a;
        cout << x << " --> x[ " << y << " : " << z << " ]\n";
    } 
    return 0;
}