#include<iostream>
#include<algorithm>

using namespace std;

bool findTriplet(int a[],int n,int sum){
    sort(a,a+n);
    for(int i=0;i<n;i++){
        int low = i+1,high = n-1;
        sum -= a[i];
        while(low<high){
            if(a[low]+a[high] == sum)return true;
            else if(a[low]+a[high]<sum)low++;
            else high--;
        }
    }
    return false;
}

int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<findTriplet(a,n,sum)<<endl;
return 0;
}
