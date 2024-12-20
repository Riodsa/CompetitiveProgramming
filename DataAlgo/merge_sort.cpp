#include<bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &v,int l,int r)
{
    for(int i=l;i<=r;++i) cout << v[i] << ' ';
    cout << '\n';
}
void Merge(vector<int> &vec,int l,int mid,int r)
{
    int idxl = l,idxr = mid+1,start = l,stop = r;
    // cout << "vecL: "; print_vec(vec,idxl,mid);
    // cout << "vecR: "; print_vec(vec,idxr,r);
    queue<int> tmp;
    while(idxl <= mid || idxr <= r)
    {
        // cout << "vec[idxl]: " << vec[idxl] << " vec[idxr]: " << vec[idxr] << '\n';
        if(idxr > r || (idxl <= mid && vec[idxl] <= vec[idxr]))
        {
            // cout << "PUSHL " << vec[idxl] << '\n';
            tmp.push(vec[idxl++]);
        }
        else
        {
            // cout << "PUSHR " << vec[idxr] << '\n';
            tmp.push(vec[idxr++]);
        }
    }
    for(int i=start;i<=stop;++i)
    {
        vec[i] = tmp.front();
        tmp.pop();
    }
    return ;
}

void Merge_Sort(vector<int> &vec,int l,int r)
{
    int mid = (l+r)/2;
    if(l >= r) return ;
    // cout << "l: " << l << " mid: " << mid << " r: " << r << '\n';
    Merge_Sort(vec,l,mid);
    Merge_Sort(vec,mid+1,r);
    Merge(vec,l,mid,r);
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> v;
    int n; cin >> n;
    for(int i=0;i<n;++i)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    Merge_Sort(v,0,n-1);
    for(int x : v) cout << x << ' ';
    cout << '\n';
    return 0;
}