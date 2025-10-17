#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        if(i - 1 >= 0) v[i] += v[i-1];
    }
    int q;
    cin>>q;
    while (q--) {
        int l, r;
        cin>>l>>r;
        l--;r--;
        int val = v[r] - ((l - 1 >= 0) ? v[l-1] : 0);
        cout<<val/10<<endl;
    }
    return 0;
}