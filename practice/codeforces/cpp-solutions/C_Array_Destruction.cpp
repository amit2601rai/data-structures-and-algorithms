#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > collectPairs(vector<int>v, int x, int sz) {
    vector<pair<int, int> > pairs;
    multiset<int> el;
    for (auto e : v) el.insert(e);
    do {
        auto itb = el.end();
        itb--;
        int b = *itb;
        el.erase(itb);
        int a = x - b;
        auto ita = el.find(a);
        if (ita == el.end()) break;
        pairs.push_back(make_pair(a, b));
        el.erase(ita);
        x = b;
        if (el.size() == 0) break;
    } while(true);
    return pairs;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sz = 2*n;
        vector<int> v(sz);
        for (int i = 0; i < sz; i++) cin >> v[i];
        sort(v.begin(), v.begin() + sz);
        int p = v[sz-1];
        bool flag = false;
        for (int i = sz-2; i >= 0; i--) {
            int q = v[i];
            int x = p + q;
            vector<pair<int, int> > pairs = collectPairs(v, x, sz);
            if (pairs.size() == n) {
                flag = true;
                cout << "YES" << endl;
                cout << x << endl;
                for (int k = 0; k < pairs.size(); k++) {
                    cout << pairs[k].first << " " << pairs[k].second << endl;
                }
                break;
            }
        }
        if (!flag) cout << "NO" << endl;
    }
    return 0;
}