#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,string> nickname,firstname;
    int n,m;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        string a,b;
        cin >> a >> b;
        firstname[a] = b;
        nickname[b] = a;
    }
    cin >> m;
    while(m--)
    {
        string s;
        cin >> s;
        // cout << "nickname : " << nickname[s] << " firstname : " << firstname[s] << '\n';
        if(!nickname[s].empty()) cout << nickname[s] << '\n';
        else if(!firstname[s].empty()) cout << firstname[s] << '\n';
        else cout << "Not found\n";
    }
    return 0;
}