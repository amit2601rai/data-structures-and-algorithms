#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        long long diffsum = 0;
        for (int i = 1; i < n; i++) {
            diffsum += (abs(v[i] - v[i-1]));
        }

        int x = abs(v[1] - v[0]);
        int y = abs(v[n-1] - v[n-2]);
        int z = max(x, y);
        for (int i = 1; i <= n-2; i++) {
            z = max(z, abs(v[i-1] - v[i]) + abs(v[i] - v[i+1]) - abs(v[i-1] - v[i+1]));   
        }
        cout<<(diffsum - z)<<endl;
    }
    return 0;
}