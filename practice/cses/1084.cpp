#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > ds(n);
    vector<int> as(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ds[i] = make_pair(x - k, x + k);
    }
    for (int i = 0; i < m; i++) {
        cin >> as[i];
    }
    sort(ds.begin(), ds.begin() + n);
    sort(as.begin(), as.begin() + m);

    int ans = 0;
    int p = 0, q = 0;
    while (p < n && q < m) {
        if (ds[p].first <= as[q] && as[q] <= ds[p].second) ans++, p++, q++;
        else if (as[q] < ds[p].first) q++;
        else p++;
    }

    cout << ans << endl;
    return 0;
}