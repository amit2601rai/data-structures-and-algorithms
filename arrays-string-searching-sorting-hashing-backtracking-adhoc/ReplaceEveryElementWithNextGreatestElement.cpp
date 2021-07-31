#include<iostream>


using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int max_val = -1,tmp;
    for(int i=n-1;i>=0;i--){
        tmp = max(max_val,a[i]);
        a[i] = max_val;
        max_val = tmp;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
return 0;
}
