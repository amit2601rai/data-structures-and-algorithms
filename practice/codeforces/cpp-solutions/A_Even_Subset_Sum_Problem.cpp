#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<int, int> > even, odd;
        for (int i = 1; i <= n; i++) {
            int x;
            cin>>x;
            if(x % 2 == 0) even.push_back(make_pair(x, i));
            else odd.push_back(make_pair(x, i));
        }
        
        if (even.size() >=1) {
            cout<<"1"<<endl;
            cout<<even[0].second<<endl;
        } else if(odd.size() >=2) {
            cout<<"2"<<endl;
            cout<<odd[0].second<<" "<<odd[1].second<<endl;
        } else {
            cout<<"-1"<<endl;
        }   
    }
    return 0;
}