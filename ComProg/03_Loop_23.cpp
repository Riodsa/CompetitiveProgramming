#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    string tmp = "";
    int len = s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i] == s[i+1])
        {
            tmp += s[i];
            continue;
        }
        else
        {
            tmp += s[i];
            if(tmp.size() < (long long unsigned int)k) cout << tmp;
            tmp = "";
            // if(tmp.size() < k) cout << tmp;
            // tmp = "";
        }
    }
    return 0;
}