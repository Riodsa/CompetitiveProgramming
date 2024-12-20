#include<bits/stdc++.h>
using namespace std;

int n,m,start;

vector<int> change;
unordered_map<int,int> change_to;
vector<int> total;

void print_total_days(int n)
{
    int day=0,sum=0,cnt=0;
    int c = start;
    cout << '\n';
    cout << "day     : ";
    for(int i=0;i<=n;++i)
    {
        printf("%2d ",i);
    }
    cout << '\n';
    cout << "collect : ";
    while(day != n+1)
    {
        if(day == change[cnt])
        {
            c = change_to[day];
            ++cnt;
        }
        printf("%2d ",c);
        day++;
    }
    cout << '\n';
    day = 0;  sum = 0;  cnt = 0;
    c = start;
    cout << "total   : ";
    while(day != n+1)
    {
        if(day == change[cnt])
        {
            c = change_to[day];
            ++cnt;
        }
        sum += c;
        printf("%2d ",sum);
        day++;
    }
    cout << "\n\n";
}

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> start;
    change.push_back(0);
    change_to[0] = start;
    total.push_back(start);
    for(int i=0;i<n;++i)
    {
        int a,s;
        cin >> a >> s;
        change.push_back(a);
        change_to[a] = s;
    }
    sort(change.begin(),change.end());
    int collect = total[0];
    for(int i=1;i<=n;++i)
    {
        collect += ((change[i]-change[i-1]-1)*start)+change_to[change[i]];
        // cout << "collect " << start << " for " << change[i]-change[i-1] << " : " << collect << '\n';
        start = change_to[change[i]];
        total.push_back(collect);
    }
    // for(int x : total) cout << x << ' ';
    // cout << '\n';
    print_total_days(15);
    for(int i=0;i<m;++i)
    {
        int p,x;
        cin >> p >> x;
        int idx_day = upper_bound(change.begin(),change.end(),x)-change.begin();
        int idx_total = upper_bound(total.begin(),total.end(),p)-total.begin();
        int idx_total_after = upper_bound(change.begin(),change.end(),x)-change.begin();
        if(idx_day!=0) idx_day--;
        if(idx_total!=0) idx_total--;
        int total_before_faked = total[idx_day] + ((x-change[idx_day])*change_to[change[idx_day]]);
        // cout << "total after faked : " << total[idx_total_after] << '\n';
        // cout << "last change before faked " << change[idx_day] << ' ';
        // cout << "total before faked " << total_before_faked << '\n';
        // cout << "idx_day : " << idx_day << " total_before : " << total[idx_total] << '\n';
        if(total_before_faked >= p)
        {
            int more_day = ceil(((double)(p-total[idx_total])/change_to[change[idx_total]]));
            more_day = max(0,more_day);
            // cout << "started day : " << change[idx_total] << " more day : " << more_day << '\n';
            cout << change[idx_total] + more_day << '\n';
        }
        else
        {
            int next_day = lower_bound(total.begin(),total.end(),total_before_faked+p)-total.begin();
        }
    }
    return 0;
}