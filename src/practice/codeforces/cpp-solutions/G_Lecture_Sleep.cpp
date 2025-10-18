#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> t(n);
    for (int i = 0;  i < n; i++) cin >> a[i];
    for (int i = 0;  i < n; i++) cin >> t[i];

    vector<int> prefixsum(n, 0);
    vector<int> prefixsumforones(n, 0);

    prefixsum[0] = a[0];
    prefixsumforones[0] = t[0]*a[0];

    for (int i = 1; i < n; i++) {
        prefixsumforones[i] = prefixsumforones[i-1] + t[i]*a[i];
        prefixsum[i] = a[i] + prefixsum[i-1];
    }

    int ans = 0;
    for (int i = 0; i+k-1 < n; i++) {
        int windowsum = prefixsum[i+k-1] - (i == 0 ? 0 : prefixsum[i-1]);
        //0 -> i-1 & i+k -> n-1
        if (i != 0){
            windowsum += prefixsumforones[i-1];
        }
        if (i + k != n) {
            windowsum += (prefixsumforones[n-1] - prefixsumforones[i+k-1]);
        }

        ans = max(ans, windowsum);
    }
    cout << ans << endl;
   
   return 0;
}