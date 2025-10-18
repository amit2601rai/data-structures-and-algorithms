#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstdio>

using namespace std;

bool mycomp(pair<int,int>u,pair<int,int>v){
    return u.second<v.second;
}

void print(vector<pair<int,int> >v){
    vector<pair<int,int> > :: iterator it;
    for(it = v.begin();it != v.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}

int cal(vector<pair<int,int> >v){
    int ans = 0,temp;
    sort(v.begin(),v.end(),mycomp);
    vector<pair<int,int> > :: iterator it;
    for(it = v.begin();it != v.end(); it++){
        if(it == v.begin()) {
                temp = (*it).second;
                ans++;
                continue;
        }
        if((*it).first >= temp){
            ans ++;
            temp = (*it).second;
        }
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k,ans = 0;
        map<int,vector<pair<int,int> > >m;
        int x,y,z;
        scanf("%d%d",&n,&k);
        while(n--){
                scanf("%d%d%d",&x,&y,&z);
                if(m.count(z)==0){
                    vector<pair<int,int> >v;
                    v.push_back(make_pair(x,y));
                    m[z] = v;
                }
                else{
                    m[z].push_back(make_pair(x,y));
                }
        }
        map<int,vector<pair<int,int> > >:: iterator it;
        for(it = m.begin();it!=m.end();it++){
            ans += cal((*it).second);
        }
        cout<<ans<<endl;
    }
    return 0;
}
