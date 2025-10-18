#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;


int cal(int n,int k){
	int dp[n+1][k+1],res;
	for(int i=1;i<=n;i++){
		dp[i][1]=1;
		dp[i][0]=0;
	}
	for(int j=1;j<=k;j++)
		dp[1][j]=j;

	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			dp[i][j]=INT_MAX;
			for(int x=1;x<=j;x++){
				res=1+max(dp[i-1][x-1],dp[i][j-x]);
				dp[i][j]=min(res,dp[i][j]);
			}
		}
	}
	return dp[n][k];
}


int main(){
	int n,k;
	cin>>n>>k;
	cout<<cal(n,k)<<endl;
return 0;
}
