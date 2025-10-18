#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>

typedef long long ll;

using namespace std;

void print(ll a[],int n){
    for(int i=1; i<=n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,k;
    ll maxV = LONG_MIN;
    cin>>n>>k;
    ll a[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
        maxV = max(maxV,a[i]);
    }
    if(k == 0){
        print(a,n);
      return 0;
    }
    for(int i=1; i<=n; i++){
        a[i] = maxV - a[i];
    }
    maxV = LONG_MIN;
    for(int i=1; i<=n; i++){
        maxV = max(maxV,a[i]);
    }
    k--;
    if(k>0){
        if(k%2 != 0){
            for(int i=1; i<=n; i++){
                a[i] = maxV - a[i];
            }
        }
    }
    print(a,n);
return 0;
}
