#include<iostream>
#include<cstdio>

using namespace std;

//Returns index Of last element < key
int bin_search(int l,int h,int a[],int key){
    while(h-l > 1){
        int mid = (l+h)/2;
        if(a[mid] >= key) h = mid - 1;
        else l = mid;
    }
    if(a[h] < key) return h;
    else if(a[l] < key) return l;
    else return 0;
}

//dp[i] : Last element Of subsequence of length i.
//So ultimate len will maximum length of subsequence.
int lis(int a[],int n){
	int dp[n+1], len=1;
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
        int idx = bin_search(1,len,dp,a[i]);
		if(idx == 0) continue;
		else if(idx == len) dp[++len] = a[i];
		else dp[idx+1] = a[i];
	}
return len;
}

int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
    cout<<lis(a,n)<<endl;
	return 0;
}
