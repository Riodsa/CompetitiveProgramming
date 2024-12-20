#include<iostream>
using namespace std;

int main()
{
    int cnt = 0;
    string tar,s;
    getline(cin,tar);
    getline(cin,s);
    int lens = s.size();
    string tmp = "";
    for(int i=0;i<lens;++i)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) tmp += s[i];
        else
        {
            if(tmp == tar) ++cnt;
            tmp = "";
        }
    }
    if(tmp == tar) ++cnt;
    cout << cnt;
    return 0;
}