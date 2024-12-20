#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> unique;
    int x;
    while(cin >> x)
    {
        if(x == -1) break;
        if(find(unique.begin(),unique.end(),x) == unique.end()) unique.emplace_back(x);
    }
    sort(unique.begin(),unique.end());
    int len = unique.size();
    cout << len << '\n';
    for(int i=0;i<min(10,len);++i) cout << unique[i] << ' ';
    return 0;
}