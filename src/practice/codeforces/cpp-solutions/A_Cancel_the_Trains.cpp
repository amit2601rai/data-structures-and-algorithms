#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(101, 0);

        int val;

        for (int i = 0; i < n; i++) {
            cin>>val;
            v[val]++;
        }

        for (int i = 0; i < m; i++) {
            cin>>val;
            v[val]++;
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            if(v[i] > 1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}