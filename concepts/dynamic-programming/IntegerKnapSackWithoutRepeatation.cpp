#include<iostream>
#include<algorithm>


using namespace std;

int knapsack(int price[],int weight[],int n,int W){
    int dp[n+1][W+1];
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int i=0; i<=W; i++)
        dp[0][i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(j-weight[i]>=0)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+price[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main(){
    int n,W;
    cin>>n>>W;
    int price[n+1];
    int weight[n+1];
    for(int i=1; i<=n; i++)
        cin>>price[i];
    for(int i=1; i<=n; i++)
        cin>>weight[i];
    cout<<knapsack(price,weight,n,W)<<endl;
return 0;
}
