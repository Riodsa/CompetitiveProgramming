#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v)
{
    for(int a : v) cout << a << ' ';
    cout << '\n';
}

void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
    auto first = a,last = b-1;
    while(first != last)
    {
        // print_vector(v);
        int tmp = *first;
        *first = *last;
        *last = tmp;
        first++;
        last--;
        if(first > last) break;
    }
}
int main() 
{
    //read input
    int n,a,b; 
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) 
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    //call function
    reverse(v,v.begin()+a,v.begin()+b+1);
    // display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    } 
    cout << endl;
}