#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter)
{
    vector<string> ans;
    string tmp = "";
    int len = line.size();
    for(int i=0;i<len;++i)
    {
        if(line[i] == delimiter)
        {
            if(tmp != "") ans.emplace_back(tmp);
            tmp = "";
            continue;
        }
        else if(i == len-1)
        {
            tmp += line[i];
            if(tmp != "") ans.emplace_back(tmp);
        }
        tmp += line[i];
    }
    return ans;
}
int main() {
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0])) 
    {
        cout << '(' << e << ')';
    }
}
