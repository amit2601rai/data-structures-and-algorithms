#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    int max_so_far = INT_MIN;
    int c = 1;
    for(int i = 1; i < n; i++) {
        if(v[i] > v[i-1]) c++;
        else max_so_far = max(c, max_so_far), c = 1;
    }
    cout<<max(max_so_far, c)<<endl;
    return 0;
}