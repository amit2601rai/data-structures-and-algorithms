#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin>>n;

    int ans = 0;
    
    //1, 5, 10, 20, 100

    vector<int> v;
    v.push_back(100);
    v.push_back(20);
    v.push_back(10);
    v.push_back(5);
    for(int i = 0; i < v.size(); i++) {
        ans = ans + n/v[i];
        n %= v[i];
    }
    ans += n;
    cout<<ans<<endl;
    return 0;
}