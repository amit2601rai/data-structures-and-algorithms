#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;


int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int p[n+1];
        fill_n(p,n+1,-1);
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            p[x] = y;
        }
        int ans = 0;
        for(int i=1; i<=n ; i++){
            if(p[i] != 0){
                int k = i;
                while(p[k] != -1){
                    int temp = k;
                    k = p[k];
                    p[temp] = 0;
                }
                p[k] = 0;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
return 0;
}
