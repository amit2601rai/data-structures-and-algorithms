#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }

        int ans = v[0];
        int ones = 0;
        for (int i = 1; i < n; ) {
            if (v[i] == 0) {i++;continue;}
            while ( i < n && v[i] == 1) {
                ones++;
                i++;
            }
            ans += (ones/3);
            ones = 0;
        }

        cout<<ans<<endl;
    }
 
    return 0;
}