#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.begin() + n);

    vector<int> m(2, 0);
    m[0] = v[n/2];
    if (n % 2 == 0)  m[1] = v[n/2 + 1];   

    long long ans = LLONG_MAX;

    for (int i = 0; i < 2; i++) {
        long long localans = 0;
        for (int j = 0; j < n; j++) {
            localans += abs(m[i] - v[j]);
        }
        ans = min(ans, localans);
    }

    cout << ans << endl;

    return 0;
}