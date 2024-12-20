#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    int x;
    int status = 0;
    while(cin >> x)
    {
        if(x == -1) break;
        if(status == 0)
        {
            v.emplace_back(x);
            status = 1;
        }
        else if(status == 1)
        {
            v.insert(v.begin(),x);
            status = 0;
        }
    }
    // for(int a : v) cout << a << ' ';
    cout << "[";
    int len = v.size();
    for(int i=0;i<len;++i)
    {
        cout << v[i];
        if(i != len-1) cout << ", ";
    }
    cout << "]";
    return 0;
}