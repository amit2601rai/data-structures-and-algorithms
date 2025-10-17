#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>


using namespace std;

int dp[1001][1001];

int LCS(char x[],char y[],int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i]==y[j])
			   dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[n][m];
}

int main()
{
	int n;
	cin>>n;
	char x[n+1];
	char y[n+1];
	for(int i=1;i<=n;i++)
		cin>>x[i];
    int k = n;
	for(int j=1;j<=n;j++)
		y[j] = x[k--];
	cout<<n-LCS(x,y,n,n)<<endl;
return 0;
}
