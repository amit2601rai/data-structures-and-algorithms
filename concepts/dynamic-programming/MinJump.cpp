#include<iostream>
#include<cstdio>
#include<climits>

using namespace std;

int minJumps(int a[],int n){
    int jumps[n];
    if(n == 0 || a[0] == 0)
        return INT_MAX;
    jumps[0] = 0;
    for(int i = 1; i<n; i++){
        jumps[i] = INT_MAX;
        for(int j = 0; j<i; j++){
            if(j+a[j] >= i && jumps[j] != INT_MAX){
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }
    return jumps[n-1];
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<minJumps(a,n)<<endl;
return 0;
}
