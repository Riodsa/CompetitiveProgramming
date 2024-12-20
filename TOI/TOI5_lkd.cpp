#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int len,len2,status = 1,ch,p;
    string tmp = "";
    while(n--)
    {
        string s;
        cin >> s;
        len = s.length();
        tmp.clear();
        for(int i=0;i<len;i+=2)
        {
            if(status == 1)
            {
                if(s[i] == '0' && s[i+1] == '0')
                {
                    tmp += '0';
                    status = 1;
                }
                else if(s[i] == '1' && s[i+1] == '1')
                {
                    tmp += '1';
                    status = 2;
                }
            }
            else if(status == 2)
            {
                if(s[i] == '0' && s[i+1] == '1')
                {
                    tmp += '1';
                    status = 4;
                }
                else if(s[i] == '1' && s[i+1] == '0')
                {
                    tmp += '0';
                    status = 3;
                }
            }
            else if(status == 3)
            {
                if(s[i] == '0' && s[i+1] == '0')
                {
                    tmp += '1';
                    status = 2;
                }
                else if(s[i] == '1' && s[i+1] == '1')
                {
                    tmp += '0';
                    status = 1;
                }
            }
            else if(status == 4)
            {
                if(s[i] == '1' && s[i+1] == '0')
                {
                    tmp += '1';
                    status = 4;
                }
                else if(s[i] == '0' && s[i+1] == '1')
                {
                    tmp += '0';
                    status = 3;
                }
            }
//            cout << "status = " << status << '\n';
//            cout << "tmp = " << tmp << '\n';
        }
        ch = 0,p = 1;
        len2 = tmp.length();
        for(int i=len2-1;i>=0;--i)
        {
            ch = ch + (tmp[i]-'0')*p;
            p *= 2;
        }
//        cout << ch << '\n';
        if(ch >= 'A' && ch <= 'Z') cout << (char)ch;
    }
    return 0;
}
