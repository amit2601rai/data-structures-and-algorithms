#include <bits/stdc++.h>

using namespace std;


long long ncr(long long n, long long k) {
    long long x = 1, y = 1;
    for (long long i = k; i >=1; i--, n--) {
        x *= n;
        y *= i;
    }
    return (x/y);
}
int main() {
    long long n, k;
    cin>>n>>k;
    long long ans = 1;
    long long v[] = {0,1,2,9}; 
    for (long long i = 1; i <= k; i++) {
        ans += (ncr(n, i) * v[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}