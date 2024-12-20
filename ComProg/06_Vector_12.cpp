#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    vec.emplace_back(n);
    while(n != 1)
    {
        if(n%2) n = 3*n+1;
        else n /= 2;
        vec.emplace_back(n);
    }
    int len = vec.size();
    for(int i=max(0,len-15);i<len;++i)
    {
        cout << vec[i];
        if(i != len-1) cout << "->";
    }
    return 0;
}