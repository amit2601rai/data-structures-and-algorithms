#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n ;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.begin() + n);

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i-1]) ans++;
    }
    cout << ans <<endl;
    return 0;
}