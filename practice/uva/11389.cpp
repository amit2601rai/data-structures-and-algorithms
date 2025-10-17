#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    int n,d,r;
    while(1){
        cin>>n>>d>>r;
        if(!(n||d||r))break;
        int morn[n];
        int even[n];
        for(int i=0; i<n ; i++)
            cin>>morn[i];
         for(int i=0; i<n ; i++)
            cin>>even[i];
        sort(morn,morn+n);
        sort(even,even+n);
        int l=0,h=n-1;
        int ans = 0;
        for(int l=0,h=n-1;l<n;l++,h--){
            int temp = morn[l]+even[h];
            if(temp > d)
                ans += (temp - d)*r;
            }
        cout<<ans<<endl;
    }
    return 0;
}
