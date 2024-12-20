#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    double cnt_order=0,sum_wait_time=0;
    int start_number=1;
    int current_customer = 0,c2=0;
    vector<int> q,t;
    for(int i=0;i<n;++i)
    {
        string s;
        cin >> s;

        if(s == "reset")
        {
            int x; cin >> x;
            start_number = x;
        }
        else if(s == "new")
        {
            int x; cin >> x;
            cout << ">> ticket " << start_number << '\n';
            q.push_back(start_number++);
            t.push_back(x);
        }
        else if(s == "next")
        {
            cout << ">> call " << q[c2++] << '\n';
        }
        else if(s == "order")
        {
            if(c2 > current_customer+1) current_customer = c2-1;
            int time; cin >> time;
            int wait_for = abs(time-t[current_customer]);
            cout << ">> qtime " << q[current_customer] << ' ' << wait_for << '\n';
            current_customer++;
            ++cnt_order;
            sum_wait_time += wait_for;
        }
        else if(s == "avg_qtime")
        {
            cout << ">> avg_qtime " << round((sum_wait_time/cnt_order)*100)/100 << '\n';
        }
    }
    return 0;
}