#include<iostream>
#include<cstring>
using namespace std;

string encryp(string s)
{
    string code = "";
    int len = s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i] == '0') code += "UUUU";
        else if(s[i] == '1') code += "UUUL";
        else if(s[i] == '2') code += "UULU";
        else if(s[i] == '3') code += "UULL";
        else if(s[i] == '4') code += "ULUU";
        else if(s[i] == '5') code += "ULUL";
        else if(s[i] == '6') code += "ULLU";
        else if(s[i] == '7') code += "ULLL";
        else if(s[i] == '8') code += "LUUU";
        else if(s[i] == '9') code += "LUUL";
        else if(s[i] == '-') code += "LULU";
        else if(s[i] == ',') code += "LULL";
    }
    return code;
}

string decode1(string s)
{
    int len = s.size();
    int p = 1,sum = 0;
    for(int i=len-1;i>=0;--i)
    {
        if(s[i] == 'L') sum += p*1;
        else sum += 0;
        p *= 2;
    }
    // cout << "sum = " << sum << ' ';
    if(sum == 10) return "-";
    else if(sum == 11) return ",";
    return to_string(sum);
}

string decode(string s)
{
    int len = s.size();
    string ans = "";
    string tmp = "";
    for(int i=0;i<len;++i)
    {
        if(i != 0 && (((i+1)%4 == 1) || i == len-1))
        {
            if(i == len-1) tmp += s[i];
            // cout << "tmp = " << tmp << '\n';
            ans += decode1(tmp);
            tmp = "";
        }
        tmp += s[i];
    }
    // cout << '\n';
    return ans;
}

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int l = s.size();
    char cmd;
    while(cin >> cmd)
    {
        if(cmd == 'E')
        {
            string x;
            cin >> x;
            string pattern = encryp(x);
            int len = pattern.size();
            int cnt = 0,c = 0;
            while(c != len)
            {
                // cout << pattern[c++];
                if((s[cnt] >= 'a' && s[cnt] <= 'z') || (s[cnt] >= 'A' && s[cnt] <= 'Z'))
                {
                    if(pattern[c] == 'L')
                    {
                        if(s[cnt] >= 'A' && s[cnt] <= 'Z')
                        {
                            cout << (char)(s[cnt++]+('a'-'A'));
                        }
                        else cout << s[cnt++];
                    }
                    else if(pattern[c] == 'U')
                    {
                        if(s[cnt] >= 'a' && s[cnt] <= 'z')
                        {
                            cout << (char)(s[cnt++]-('a'-'A'));
                        }
                        else cout << s[cnt++];
                    }
                    c++;
                }
                else
                {
                    cout << s[cnt++];
                }
                if(cnt == l) cnt = 0;
            }
            cout << '\n';
        }
        else if(cmd == 'D')
        {
            string x;
            string code = "";
            getline(cin,x);
            int len = x.size();
            for(int i=0;i<len;++i)
            {
                if(x[i] >= 'a' && x[i] <= 'z') code += 'L';
                else if(x[i] >= 'A' && x[i] <= 'Z') code += 'U';
            }
            // cout << "Code = " << code << '\n';
            cout << decode(code) << '\n';
        }
    }
    return 0;
}