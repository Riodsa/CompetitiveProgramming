#include<iostream>
#include<algorithm>
using namespace std;

void print_array(int pancake[],int n)
{
    for(int i=1;i<=n;++i) cout << pancake[i] << ' ';
    cout << '\n';
}

void flip_pancake(int pancake[],int swap_point,int n)
{
    if(swap_point == -1)
    {
        for(int i=1;i<=n/2;++i)
        {
            // cout << "SWAP1\n";
            swap(pancake[i],pancake[n-i+1]);
        }
    }
    else
    {
        for(int i=1;i<=swap_point/2;++i)
        {
            // cout << "SWAP2\n";
            swap(pancake[i],pancake[swap_point-i+1]);
        }
    }
    // print_array(pancake,n);
}


int main()
{
    int n;
    cin >> n;
    int pancake[n+1],sorted[n+1],corr = 0,mx;
    for(int i=1;i<=n;++i)
    {
        cin >> pancake[i];
        sorted[i] = pancake[i];
    }
    print_array(pancake,n);
    sort(sorted+1,sorted+n+1);
    mx = sorted[n-corr];
    while(mx != sorted[1])
    {
        bool found_correct_pos = false;
        for(int i=1;i<=n && !found_correct_pos;++i)
        {
            if(pancake[i] == mx)
            {
                if(i == 1)
                {
                    flip_pancake(pancake,-1,n-corr);
                    print_array(pancake,n);
                    ++corr;
                    mx = sorted[n-corr];
                    found_correct_pos = true;
                }
                else if(i == n-corr)
                {
                    ++corr;
                    mx = sorted[n-corr];
                    found_correct_pos = true;
                }
                else 
                {
                    flip_pancake(pancake,i,n);
                    print_array(pancake,n);
                    found_correct_pos = true;
                }
            }
        }
    }
    return 0;
}