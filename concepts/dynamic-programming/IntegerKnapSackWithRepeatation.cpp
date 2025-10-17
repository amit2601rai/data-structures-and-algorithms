#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>


using namespace std;

int dp[10001];

int main(){
	int n;
	cin>>n;
	int price[n+1];
	int size[n+1];
	int C;
    cin>>C;
	for(int i=1;i<=n;i++)
		cin>>price[i];
	for(int j=1;j<=n;j++)
		cin>>size[j];
	for(int i=1;i<=C;i++){
		dp[i]=0;
		for(int j=1;j<=n;j++){
			if(i-size[j] >= 0) dp[i]=max(dp[i],dp[i-size[j]]+price[j]);
		}
	}
	cout<<dp[C]<<endl;
return 0;
}
