#include<iostream>
using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        int len = s.size();
        bool haveL=false,haveS=false,haveN=false,haveX=false;
        for(int i=0;i<len;++i)
        {
            if(s[i] >= 'A' && s[i] <= 'Z') haveL = true;
            else if(s[i] >= 'a' && s[i] <= 'z') haveS = true;
            else if(s[i] >= '0' && s[i] <= '9') haveN = true;
            else haveX = true;
        }
        if(len >= 12 && haveL && haveS && haveN && haveX) cout << ">> strong\n";
        else if(len >= 8 && haveL && haveS && haveN) cout << ">> weak\n";
        else cout << ">> invalid\n";
    }
    return 0;
}