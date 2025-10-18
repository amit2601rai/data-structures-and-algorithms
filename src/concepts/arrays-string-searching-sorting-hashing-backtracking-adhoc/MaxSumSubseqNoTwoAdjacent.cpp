#include<iostream>

using namespace std;

int maxSumNoTwoAdjacent(int a[],int n){
    int dp[2][n];
    dp[0][0]=0;
    dp[1][0]=a[0];
    for(int i=1;i<n;i++){
        dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
        dp[1][i] = dp[0][i-1]+a[i];
    }
    return max(dp[0][n-1],dp[1][n-1]);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxSumNoTwoAdjacent(a,n)<<endl;
return 0;
}
