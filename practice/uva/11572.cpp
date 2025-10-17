#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>v(n);
        int ans = -1;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int low,high,i;
        i = low = high = 0;
        map<int,int>m;
        int index;
        while(i < n){
            if(m.count(v[i]) == 0){
                    high = i;
                    m[v[i]] = i;
            }else{
                    index = m[v[i]];
                    ans = max(ans,high - low +1);
                    low = index + 1;
                    high = i;
                    m.clear();
                    for(int k = low ;k<=high;k++)
                        m[v[k]] = k;
            }
            i++;
        }
        cout<<max(ans,high-low+1)<<endl;
    }
return 0;
}
