#include <bits/stdc++.h>
using namespace std;
bool arr[20000000];
int main() {

	int n, out = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int func;cin >> func;
		if (func == 1) {
			int l,r;
			cin>>l>>r;
			while(l <= r){
				if(arr[l-1]==0 && arr[l]==0 && arr[l+1]==0) out++;
				if(arr[l-1]==1 && arr[l]==0 && arr[l+1]==1) out--;
				arr[l] = 1;
                ++l;
			}
		}else cout << out << '\n';
	}
    return 0;
}

