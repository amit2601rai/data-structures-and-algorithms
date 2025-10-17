#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    long long totalsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        totalsum += v[i];
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++) {
        long long halfsum1 = 0;
        for (int k = 1; k <= n; k++) {
            if ((1<<k) & i) {
                halfsum1 += v[k-1];
            }
        }
        long long halfsum2 = totalsum - halfsum1;
        ans = min(ans, abs(halfsum1 - halfsum2));
    }
    cout << ans << endl;

    return 0;
}