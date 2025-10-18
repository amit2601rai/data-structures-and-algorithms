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

#define INF INT_MAX
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)


int findSet(int x,int par[]){
    if(x != par[x])par[x] = findSet(par[x],par);
    return par[x];
}

void mergeSets(int x, int y,int par[],int maxCost[],int owner[]){
    int px = findSet(x,par);
    int py = findSet(y,par);
    if(maxCost[owner[px]] == maxCost[owner[py]])return;
    else if(maxCost[owner[px]] > maxCost[owner[py]]){
        par[py] = px;
    }else{
        par[px] = py;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int cost[n+1];
        int owner[n+1];
        int maxCost[n+1];
        int par[n+1];
        FOR(i,1,n){
            scanf("%d",&cost[i]);
            par[i] = i;
            owner[i] = i;
            maxCost[i] = cost[i];
        }
        int Q,flag,x,y;
        scanf("%d",&Q);
        while(Q--){
            scanf("%d",&flag);
            if(flag){
                scanf("%d",&x);
                printf("%d\n",owner[findSet(x,par)]);
            }else{
                scanf("%d%d",&x,&y);
                if(findSet(x,par) == findSet(y,par))printf("Invalid query!\n");
                else mergeSets(x,y,par,maxCost,owner);
            }
        }
     }
return 0;
}
