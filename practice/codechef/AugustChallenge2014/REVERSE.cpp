/*Amit Rai(IIIT Hyderabad)*/
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

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define tr(container,it) for(it = container.begin(); it!= container.end(); it++)

int main(){
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    vi G[n+1];
    while(m--){
        scanf("%d%d",&x,&y);
        if(x == y )continue;
        G[x].pb(y);
        G[y].pb((-1)*x);
    }
    priority_queue<ii,vector<ii>, greater<ii> > Q;
    vi D(n+1,1000000);
    Q.push(mp(0,1));
    D[1]=0;
    while(!Q.empty()){
        ii top = Q.top();
        Q.pop();
        int v = top.second, d = top.first;
        if(d <= D[v]){
            for(int i = 0; i < G[v].size(); i++){
                int v2 = G[v][i], cost = 0;
                if(v2 < 0){
                   v2 *= (-1);
                   cost = 1;
                }
                if(D[v2] > D[v] + cost){
                   D[v2] = D[v] + cost;
                   Q.push(mp(D[v2], v2));
                }
            }
        }
    }
    if(D[n] != 1000000)printf("%d\n",D[n]);
    else printf("-1\n");
return 0;
}
