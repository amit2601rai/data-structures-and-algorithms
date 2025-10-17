#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int ans = 0;
    int d = 5;
    while (n/d >= 1) {
        ans += (n/d);
        d *= 5;
    }
    cout<<ans<<endl;
    return 0;
}