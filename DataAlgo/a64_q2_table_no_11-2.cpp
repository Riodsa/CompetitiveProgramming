#include <iostream>
using namespace std;

const int MOD = 100000007;
long long calculate_a_n(int n) {
    if (n == 0) return 1;
    if (n == 1) return 3;

    long long a_0 = 1, a_1 = 3, a_n;
    for (int i = 2; i <= n; i++) {
        a_n = (2 * a_1 + a_0) % MOD;
        a_0 = a_1;
        a_1 = a_n;
    }

    return a_n;
}

int main() {
    int n;
    cin >> n;
    cout << calculate_a_n(n);
    return 0;
}
