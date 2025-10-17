#include <bits/stdc++.h>
 
using namespace std;

set<int> getDigits(int n) {
    set<int> digits;
    while(n > 0) {
        digits.insert(n%10);
        n /= 10;
    }
return digits;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, INT_MAX);
    for (int i = 1; i <= 9; i++) dp[i] = 1;
    for (int i = 10; i <= n; i++) {
        set<int> digits = getDigits(i);
        for (auto d : digits) {
            if (dp[i-d] != INT_MAX) dp[i] = min(dp[i], dp[i-d] + 1);
        }
    }
    cout << dp[n] << endl;
}