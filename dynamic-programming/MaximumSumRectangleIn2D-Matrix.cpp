#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;


int maxSumInArray(int dp[],int n){
	int ans=INT_MIN;
	for(int i=1;i<n;i++){
		dp[i]=max(dp[i],dp[i]+dp[i-1]);
        ans=max(ans,dp[i]);
	}
return ans;
}

int maxSumRectangle(int m,int n){
    int dp[m][n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>dp[i][j];
    for(int j=0; j<n; j++)
        for(int i=1; i<m; i++)
            dp[i][j] = dp[i][j]+dp[i-1][j];
   int ans = INT_MIN;
   for(int s_row=0; s_row<m; s_row++){
        for(int e_row = s_row; e_row<m; e_row++){
            int tmp[n];
            for(int j=0; j<n; j++){
                if(s_row == 0)tmp[j] = dp[e_row][j];
                else tmp[j] = dp[e_row][j] - dp[s_row-1][j];
            }
            ans = max(ans,maxSumInArray(tmp,n));
        }
   }
   return ans;
}

int main(){
    int n,m;
    cin>>m>>n;
    cout<<maxSumRectangle(m,n)<<endl;
return 0;
}
