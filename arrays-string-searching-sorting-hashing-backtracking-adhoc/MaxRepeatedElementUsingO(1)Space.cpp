#include<iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    int max_so_far = -1;
    int max_so_far_index;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        a[a[i]%k] += k;
        if(a[i] > max_so_far){
            max_so_far = a[i];
            max_so_far_index = i;
        }
    }
    cout<<max_so_far<<" "<<max_so_far_index<<endl;
return 0;
}
