#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,string> map_number,map_name;
    int n;
    cin >> n;
    getchar();
    for(int i=0;i<n;++i)
    {
        string firstname,surname,number;
        cin >> firstname >> surname >> number;
        string name = string(firstname + ' ' + surname);
        map_name[name] = number;
        map_number[number] = name;
        // cout << "name = " << name << " number = " << number << '\n';
    }
    int m;
    cin >> m;
    getchar();
    while(m--)
    {
        string str;
        getline(cin,str);
        if(!map_name[str].empty()) cout << str << " --> " << map_name[str] << '\n';
        else if(!map_number[str].empty()) cout << str << " --> " << map_number[str] << '\n';
        else cout << str << " --> Not found\n";
    }
    return 0;
}