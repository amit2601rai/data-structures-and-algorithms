#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n; i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.begin()+n);
    int q;
    cin>>q;
    while(q--) {
        int x;
        cin>>x;
        vector<int>::iterator ub = upper_bound(v.begin(), v.end(), x);
        if (ub == v.end()) {
            cout<<n<<endl;
        } else cout<<ub - v.begin()<<endl; 
    }
    return 0;
}