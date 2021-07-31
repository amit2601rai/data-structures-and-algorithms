#include<iostream>

using namespace std;

bool isSubArraySum(int a[],int n,int sum){
    int tmp = 0,i = 0;
    for(int j=0;j<n;j++){
        while(sum<tmp+a[j]){
            tmp -= a[i++];
        }
        tmp += a[j];
        if(sum == tmp){
            cout<<i<<" "<<j<<endl;
            return true;
        }
    }
 return false;
}


int main(){
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<isSubArraySum(a,n,sum)<<endl;
return 0;
}
