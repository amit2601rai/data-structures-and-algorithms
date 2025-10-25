#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>


#define MAXN 1001
#define LOGMAXN 11
#define pb  push_back
#define make_pair mp

using namespace std;


vector<int>v[MAXN];
int visited[MAXN];
int P[LOGMAXN][MAXN];
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


void preCompute(int n){
    for(int i=1; i<=n; i++)P[0][i] = T[i];
    for(int i = 1; i<LOGMAXN; i++)for(int j=1; j<=n; j++)if(P[i-1][j] != 0)P[i][j] = P[i-1][P[i-1][j]];
}

int LCA(int u, int v) {
	if(L[u] < L[v]) swap(u,v);
	int diff = L[u] - L[v];
	for(int i=0; i<LOGMAXN; i++)if((diff>>i)&1)u = P[i][u];
	if(u == v) return u;
	for(int i=LOGMAXN-1; i>=0; i--)if(P[i][u] != P[i][v]) u = P[i][u],v = P[i][v];
	return P[0][u];
}

int main(){
    int n,m;
    cin>>n>>m;
    getTreeInput(m);
    bfs(1);
    preCompute(n);
    int Q;
    cin>>Q;
    while(Q--){
        int x,y;
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;
    }
return 0;
}
