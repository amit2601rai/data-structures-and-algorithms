#include<iostream>
#include<algorithm>

using namespace std;

int LIS_DIS(int h[],int w[],int n,bool flag){
    int dp[n+1];
    for(int i=1;i<=n;i++)
        dp[i] = w[i];
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
                if(flag){
                    if(h[j] < h[i]){
                        dp[i] = max(dp[i],dp[j]+w[i]);
                    }
                }
                else{
                        if(h[j] > h[i]){
                        dp[i] = max(dp[i],dp[j]+w[i]);
                    }

                }
            }
        }
    int tempmax = dp[1];
    for(int i=2;i<=n;i++){
            tempmax=max(tempmax,dp[i]);
    }
    return tempmax;
}




int main(){
    int T;
    cin>>T;
    int cases = 1;
    while(T--){
        int n;
        cin>>n;
        int h[n+1];
        int w[n+1];
        for(int i=1;i<=n;i++)
            cin>>h[i];
        for(int i=1;i<=n;i++)
            cin>>w[i];
        int inc = LIS_DIS(h,w,n,true);
        int dec = LIS_DIS(h,w,n,false);
        if(inc >= dec)
            cout<<"Case "<<cases<<". Increasing ("<<inc<<"). Decreasing ("<<dec<<")."<<endl;
        else
            cout<<"Case "<<cases<<". Decreasing ("<<dec<<"). Increasing ("<<inc<<")."<<endl;
      cases++;
    }
return 0;
}
