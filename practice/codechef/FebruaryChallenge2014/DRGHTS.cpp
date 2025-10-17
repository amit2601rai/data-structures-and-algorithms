/*Author:Amit(IIIT-H)*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define INF INT_MAX
#define NINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;

int dis[50005];
int visited[50005];
int tot_count;


int dfs(int s,vector<int>v[],int num,int a[]){
    int len = v[s].size();
    if(a[s] == 1){
        tot_count++;
        FOR(i,0,len-1){
            if(visited[v[s][i]] == 0){
                visited[v[s][i]] = num;
                dis[v[s][i]] = dfs(v[s][i],v,num,a);
            }
            if(dis[v[s][i]] != INF){
                tot_count += dis[v[s][i]];
            }
       }
       dis[s] = 0;
    }
    else{
        int counter = 0;
        int val = 0;
        FOR(i,0,len-1){
            if(visited[v[s][i]] == 0){
                visited[v[s][i]] = num;
                dis[v[s][i]] = dfs(v[s][i],v,num,a);
            }
            if(dis[v[s][i]] != INF){
                counter++;
                val += dis[v[s][i]];
            }
        }
        if(counter > 1){
                tot_count += (val+1);
                dis[s] = 0;
        }
        else if(counter == 1){
                dis[s] = val+1;
        }
        else
            dis[s] = INF;
    }
    return dis[s];
}

int main(){
    int n,m;
    int ans_count = 0;
    cin>>n>>m;
    int a[n+1];
    vector<int>v[n+1];
    FOR(i,1,n)cin>>a[i];
    memset1d(dis,50004,INF);
    while(m--){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int num = 0;
    FOR(i,1,n){
        tot_count = 0;
        if(visited[i] == 0){
            ++num;
            visited[i] = num;
            dfs(i,v,num,a);
        }
        if(tot_count>1)ans_count += tot_count;
    }
    long long ans = 0;
    long long cal[num+1];
    memset1d(cal,num,0);
    FOR(i,1,n) if(a[i] == 1) cal[visited[i]]++;
    FOR(i,1,num) ans += (cal[i]*(cal[i]-1))/2;
    cout<<ans<<" "<<ans_count<<endl;
return 0;
}
