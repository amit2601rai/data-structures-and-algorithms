#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> x;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long ans = v[0];
    for (int i = 1; i < n; i++) {
        v[i] = max (v[i], v[i-1] + v[i]);
        ans = max (ans, v[i]);
    }
    cout << ans << endl;
    return 0;
}