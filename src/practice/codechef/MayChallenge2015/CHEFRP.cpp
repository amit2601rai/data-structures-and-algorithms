#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        long long x, min_x, sum = 0, ans;
        min_x = 1000000;
        for (int i = 0; i < n; i++){
            cin>>x;
            min_x = min(x, min_x);
            sum += x;
        }
        ans = sum - min_x + 2;
        if (min_x < 2) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
return 0;
}
