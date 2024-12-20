#include<iostream>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        string SecretCode = "";
        int len = s.size();
        bool add = false;
        char sign = s[len-1];
        for(int i=0;i<len;++i)
        {
            if(s[i] == sign)
            {
                if(add) add = false;
                else add = true;
                continue;
            }
            if(add) SecretCode += s[i];
        }
        cout << SecretCode << '\n';
    //     cout << '\n';
    }
    return 0;
}