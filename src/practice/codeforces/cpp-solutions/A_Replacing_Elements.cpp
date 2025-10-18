#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] <= d) flag++;
        }
        if (flag == n) {
            cout << "YES" << endl;
        } else {
            sort(v.begin(), v.begin() + n);
            if (v[0] + v[1] <= d) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}