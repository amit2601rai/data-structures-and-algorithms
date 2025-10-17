#include <bits/stdc++.h>

using namespace std;

int dp [105];

void precompute() {
    dp[1] = 1;
    dp[2] = 5;
    for (int i = 3; i < 105; i++) {
        dp[i] = dp[i-1]+ 4 + 4*(i-2);
    }
}

int main() {
    int n;
    cin>>n;
    precompute();
    cout<<dp[n]<<endl;
    return 0;
}