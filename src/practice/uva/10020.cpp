#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define MINVAL -1000000000

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int m;
        cin>>m;
        vector<pair<int,int> >aux;
        while(1){
            int x,y;
            cin>>x>>y;
            if(x == 0 && y == 0)break;
            if(y <= 0)continue;
            if(m <= x) continue;
            aux.push_back(make_pair(x,y));
        }
        sort(aux.begin(),aux.end());
        int leng = aux.size();
        vector<pair<int,int> >ans;
        int key = 0,u,v,index=0;
        int flag = 0;
        while(1){
            u=MINVAL;
            v=MINVAL;
            while(index < leng &&aux[index].first <= key){
                if(aux[index].second > v){
                    u = aux[index].first;
                    v = aux[index].second;
                }
                index++;
            }
            ans.push_back(make_pair(u,v));
            key = v;
            if(v>=m)
                break;
            else if(v == MINVAL){
                cout<<"0"<<"\n\n";
                flag = 1;
                break;
            }

        }
        if(flag)continue;
        sort(ans.begin(),ans.end());
        int len = ans.size();
        cout<<len<<endl;
        for(int i=0;i<len;i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        cout<<endl;
    }
return 0;
}
