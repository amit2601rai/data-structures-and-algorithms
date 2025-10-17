#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i = 0; i < n ; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    int p = 0, q =  n - 1;
    int ans = 0;
    while (p <= q) {
        if (v[p] + v[q] <= x) p += 1, q -= 1;
        else q--;
        ans++;
    }
    cout << ans << endl;
    return 0;
}