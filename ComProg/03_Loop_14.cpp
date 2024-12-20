#include<iostream>
using namespace std;

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int lena = a.size() , lenb = b.size();
    if(lena != lenb) cout << "Incomplete answer";
    else
    {
        int cnt = 0;
        for(int i=0;i<lena;++i) if(a[i] == b[i]) ++cnt;
        cout << cnt;
    }
    return 0;
}