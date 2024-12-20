#include<iostream>
using namespace std;

int main()
{
    string firstname[11] = {"Robert","William","James","John","Margaret","Edward","Sarah","Andrew","Anthony","Deborah"};
    string nickname[11] = {"Dick","Bill","Jim","Jack","Peggy","Ed","Sally","Andy","Tony","Debbie"};
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        bool found = false;
        for(int i=0;i<11;++i)
        {
            if(s == firstname[i])
            {
                found = true;
                cout << nickname[i] << '\n';
            }
            else if(s == nickname[i])
            {
                found = true;
                cout << firstname[i] << '\n';
            }
        }
        if(!found) cout << "Not found\n";
    }
    return 0;
}