#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v[i] = make_pair(val, i);
    }
    sort(v.begin(), v.begin() + n);
    int ans = 0;
    int prev = INT_MAX;
    for (int i = 0; i < n; i++) {
        pair<int, int> p = v[i];
        if (p.second < prev) ans++;
        prev = p.second;
    }
    cout << ans << endl;

    return 0;
}