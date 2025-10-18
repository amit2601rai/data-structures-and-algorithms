#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i<n; i++) {
        cin>>v[i];
    }

    int walks = 0;
    for (int  i = 1; i < n; i++) {
        if(v[i-1] + v[i] < k) {
            walks += (k - v[i-1] - v[i]);
            v[i] += (k - v[i-1] - v[i]);
        }
    }
    cout<<walks<<endl;
    for (int i = 0; i < n; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}