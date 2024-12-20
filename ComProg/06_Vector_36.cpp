#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string grade[8] = {"A","B+","B","C+","C","D+","D","F"};
string add_grade(string c)
{
    int idx;
    for(int i=0;i<8;++i)
    {
        if(c == grade[i]) idx = i;
    }
    if(idx > 0) idx--;
    return grade[idx];
}

string minus_grade(string c)
{
    int idx;
    for(int i=0;i<8;++i)
    {
        if(c == grade[i]) idx = i;
    }
    if(idx < 7) ++idx;
    return grade[idx];
}

struct Student
{
    string id;
    string grade;
    int idx;

    bool operator<(const Student &x)&{
        if(x.grade != grade)
        {
            if(x.grade[0] == grade[0]) return grade.size() > x.grade.size();
            return x.grade > grade;
        }
        return idx < x.idx;
    }
};

int main()
{
    int n; cin >> n;
    vector<Student> vec;
    for(int i=0;i<n;++i)
    {
        string s,g;
        cin >> s >> g;
        vec.push_back({s,g,i});
    }
    string str;
    while(cin >> str)
    {
        if(str == "X") break;
        char x = str[str.size()-1];
        string id = str.substr(0,str.size()-1);
        // cout << id << ' ' << x << '\n';
        for(int i=0;i<n;++i)
        {
            if(vec[i].id == id)
            {
                // cout << id << ' ' << vec[i].grade << " -> ";
                if(x == '+') vec[i].grade = add_grade(vec[i].grade);
                if(x == '-') vec[i].grade = minus_grade(vec[i].grade);
                // cout << vec[i].grade << '\n';
                break;
            }
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;++i)
    {
        cout << vec[i].id << ' ' << vec[i].grade << '\n';
    }
    return 0;
}