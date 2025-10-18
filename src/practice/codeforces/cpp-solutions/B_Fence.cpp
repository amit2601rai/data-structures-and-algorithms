#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    queue<int> q;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        q.push(i);
        sum += v[i];
    }
    int minsum = sum;
    int ans = 0;
    for (int i = k; i < n; i++) {
        int x = q.front();
        q.pop();
        sum -= v[x];
        sum += v[i];
        q.push(i);
        if (sum < minsum) {
            sum = minsum;
            ans = q.front();
        }
    }
    cout<<ans+1<<endl;
    return 0;
}