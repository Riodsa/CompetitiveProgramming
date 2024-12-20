#include<iostream>
#include<cstring>
using namespace std;

string sum_string(string a,string b)
{
    string s = "";
    int len = max(a.size(),b.size());
    a = string(len-a.size(),'0') + a;
    b = string(len-b.size(),'0') + b;
    // cout << "a = " << a << " b = " << b << '\n';
    int add = 0;
    for(int i=len-1;i>=0;--i)
    {
        int x = a[i]-'0'; int y = b[i]-'0';
        int z = x + y + add;
        // cout << "x = " << x << " y = " << y << " z = " << z << '\n';
        add = z/10;
        z %= 10;
        s = to_string(z) + s;
    }
    if(add > 0) s = to_string(add) + s;
    return s;
}
int main()
{
    string tmp = "";
    string s = "";
    while(cin >> s)
    {
        if(s == "END") break;
        tmp = sum_string(tmp,s);
        // cout << tmp << '\n';
    }
    cout << tmp;
    return 0;
}