#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    unordered_map<string,vector<string>> mp;
    string str,animal;
    vector<string> order_animal;
    while(cin >> str >> animal)
    {
        if(str == "X") break;
        if(mp[animal].empty()) order_animal.push_back(animal);
        mp[animal].push_back(str);
    }
    for(string c : order_animal)
    {
        cout << c << ": ";
        for(string x : mp[c]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}