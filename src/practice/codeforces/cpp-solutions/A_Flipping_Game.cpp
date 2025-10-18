#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    for (int i = 1; i < n; i++) {
        v[i] += v[i-1];
    }

    int ans = 0;
    int allones = v[n-1];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int len = j - i + 1;
            int ones = (i == 0) ? v[j] : v[j] - v[i-1];
            int zeroes = len  - ones;
            ans = max(ans, zeroes + (allones - ones));
        }
    }
    cout<<ans<<endl;
    return 0;
}