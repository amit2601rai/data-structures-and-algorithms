#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> lastIdx;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        lastIdx[v[i]] = -1;
    }
    int ans = 1;
    int s = 0, e = 0, idx = 0;
    while (idx < n) {
        if (lastIdx[v[idx]] != -1) {
            s = max(s, lastIdx[v[idx]] + 1);
        } 
        e = idx;
        ans = max (ans , e - s + 1);
        //cout << s << e << endl;
        lastIdx[v[idx]] = idx;
        idx++;
    }
    cout << ans << endl;
    return 0;
}
