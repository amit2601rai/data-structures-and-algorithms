#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        ms.insert(val);
    }
    for (int j = 0; j < m; j++) {
        int val;
        cin >> val;
        if (ms.size() == 0) {cout << "-1";continue;}
        auto it = ms.lower_bound(val);
        if (it != ms.end()) {
            if ((*it) == val) {cout << (*it) << endl;ms.erase(it);}
            else {
                if (it != ms.begin()) it--;
                if ((*it) < val) {cout << (*it) << endl;ms.erase(it);}
                else cout << "-1" << endl;
            }
        } else {
            it--;
            cout << (*it) << endl;
            ms.erase(it);
        }
    }
    return 0;
}