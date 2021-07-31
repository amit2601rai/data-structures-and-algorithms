#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

int dp[2010][2010];

int editDistance(char x[],char y[],int m,int n){
    for(int i=0;i<=m;i++)
        dp[i][0]=i;
    for(int j=0;j<=n;j++)
        dp[0][j]=j;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int rep = ((x[i-1] == y[j-1]) ? 0 : 1);
            dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+rep));
        }
    }
return dp[m][n];
}



int main(){
  int t,m,n;
  cin>>t;
  while(t--){
    char x[2010];
    char y[2010];
    cin>>x;
    cin>>y;
    m = strlen(x);
    n = strlen(y);
    cout<<editDistance(x,y,m,n)<<endl;
  }
return 0;
}
