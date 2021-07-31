#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>


#define MAXN 1001
#define pb  push_back
#define make_pair mp
#define init(a) for(int i=0; i<MAXN; i++)a[i] = 0

using namespace std;


vector<int>v[MAXN];
int visited[MAXN];
int P[MAXN];
int T[MAXN];
int L[MAXN];

void getTreeInput(int num_edges){
    int x,y;
    while(num_edges--){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
}

void bfs(int s){
    visited[s] = 1;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i=0; i<v[x].size(); i++){
            if(visited[v[x][i]] == 0){
                visited[v[x][i]] = 1;
                T[v[x][i]] = x;
                L[v[x][i]] = L[x] + 1;
                Q.push(v[x][i]);
            }
        }
    }
}

int getSectionLen(int n){
    int height = -1;
    for(int i=1; i<=n; i++){
        height = max(L[i],height);
    }
return (int)(sqrt((double)height));
}

void dfs(int node,int nr){
    visited[node] = 1;
    if(L[node] < nr)
        P[node] = 1;
    else if(L[node]%nr == 0)
        P[node] = T[node];
    else
        P[node] = P[T[node]];
    for(int i = 0; i < v[node].size(); i++){
        if(visited[v[node][i]] == 0){
            dfs(v[node][i],nr);
        }
    }
}

int LCA(int x, int y){
    while (P[x] != P[y])
        if (L[x] > L[y])
            x = P[x];
        else
            y = P[y];
    while (x != y)
        if (L[x] > L[y])
            x = T[x];
        else
            y = T[y];
return x;
}
void print(int n){
    for(int i=1; i<=n; i++){
        cout<<"Node : "<<i<<" Parent : "<<T[i]<<" Level : "<<L[i]<<" Parent In Next Section : "<<P[i]<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    getTreeInput(m);
    bfs(1);
    int nr = getSectionLen(n);
    init(visited);
    dfs(1,nr);
    print(n);
    int Q;
    cin>>Q;
    while(Q--){
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
return 0;
}
