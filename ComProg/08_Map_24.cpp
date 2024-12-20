#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n;
    double total_sales = 0;
    map<string,double> price,sales;
    double top_sales = -1;
    for(int i=0;i<n;++i)
    {
        string name;
        double cost;
        cin >> name >> cost;
        price[name] = cost;
    }
    cin >> m;
    for(int i=0;i<m;++i)
    {
        string name;
        double amount;
        cin >> name >> amount;
        if(price[name] != 0)
        {
            sales[name] += amount*price[name];
            total_sales += amount*price[name];
            if(top_sales < sales[name])
            {
                top_sales = sales[name];
            }
        }
    }
    if(total_sales > 0)
    {
        cout << "Total ice cream sales: " << total_sales << '\n';
        cout << "Top sales: ";
        for(auto x : sales)
        {
            if(x.second == top_sales) cout << x.first << ' ';
        }
    }
    else if(total_sales == 0)  cout << "No ice cream sales";
    return 0;
}