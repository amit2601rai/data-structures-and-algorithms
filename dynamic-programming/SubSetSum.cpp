#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

bool isSubsetSum(int a[], int n, int sum){
    bool subset[n+1][sum+1];
    for(int i=0; i<=n; i++)
        subset[i][0] = true;
    for(int i=1; i<=sum; i++)
        subset[0][i] = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            subset[i][j] = subset[i-1][j];
            if(j-a[i] >= 0)
                subset[i][j] = subset[i][j] || subset[i-1][j-a[i]];
        }
    }
    return subset[n][sum];
}
int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    cout<<isSubsetSum(a,n,sum)<<endl;
return 0;
}
