#include<iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string tmp = "";
    int len = s.size();
    for(int i=0;i<=len;++i)
    {
        if(i == len) cout << tmp;
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(!tmp.empty()) cout << tmp << ", ";
            tmp = "";
        }
        else if(s[i] >= '0' && s[i] <= '9')
        {
            if(i-1 >= 0 && !(s[i-1] >= '0' && s[i-1] <= '9'))
            {
                cout << tmp << ", ";
                tmp = "";
            }
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(s[i-1] >= '0' && s[i-1] <= '9')
            {
                cout << tmp << ", ";
                tmp = "";
            }
        }
        tmp += s[i];
    }
    return 0;
}