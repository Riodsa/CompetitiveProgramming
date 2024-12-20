#include<iostream>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int len = s.size();
    bool have_parentheses = false;
    for(int i=0;i<len;++i)
    {
        if(s[i] == '[') cout << "(";
        else if(s[i] == ']') cout << ")";
        else if(s[i] == '(') cout << "[";
        else if(s[i] == ')') cout << "]";
        else cout << s[i];
    }
    return 0;
}