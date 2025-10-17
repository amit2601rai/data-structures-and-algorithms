#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
	int n,ans=-1;
	cin>>n;
	int dp[n+1];
	int input[n+1];
	for(int i=1;i<=n;i++) cin>>input[i];
	//BASE CASE
	if(n == 1) {cout<<input[1]<<endl;return 0;}
    if(n == 2) {cout<<max(input[1], input[2])<<endl;return 0;}

	dp[1] = input[1];
	dp[2] = input[2];
	for(int i=2;i<=n;i++){
	    dp[i]=max(dp[i-1],max(dp[i],dp[i]+dp[i-2]));
        ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
return 0;
}
