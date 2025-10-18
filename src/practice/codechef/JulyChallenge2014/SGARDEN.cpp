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
#define mod 1000000007

int visited[100001];

void dfs(int graph[],int s,int k){
    visited[s] = k;
    if(graph[s] != s)if(visited[graph[s]] == 0)dfs(graph,graph[s],k);
}

void factorization(int n,int tmp[]){
    int c;
    for(int i = 2; i*i <= n; i++){
        c = 0;
        while(n%i == 0){n /= i,c++;}
        if(c > 0)tmp[i] = c;
        if(n == 1)break;
    }
    if(n > 1)tmp[n] = 1;
}

void lcm(int ans[],int tmp[],int n){
    FOR(i,1,n){
        ans[i] = max(ans[i],tmp[i]);
    }
}

LL power(LL a,LL b){
    LL x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%mod;
        }
        y=(y*y)%mod;
        b /= 2;
    }
    return x%mod;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x;
        scanf("%d",&n);
        int graph[n+1];
        memset1d(visited,100000,0);
        FOR(i,1,n){
            scanf("%d",&graph[i]);
        }
        int k = 1;
        FOR(i,1,n){
            if(visited[i] == 0)dfs(graph,i,k++);
        }
        int val[k];
        memset1d(val,k-1,0);
        FOR(i,1,n){
            val[visited[i]]++;
        }
        int ans[n+1];
        memset1d(ans,n,0);
        FOR(i,1,k-1){
            int t = val[i];
            int tmp[t+1];
            memset1d(tmp,t,0);
            factorization(val[i],tmp);
            lcm(ans,tmp,val[i]);
        }
        LL whistles = 1;
        FOR(i,1,n){
            if(ans[i] != 0){
                whistles *= power((LL)i,(LL)ans[i]);
                if(whistles >= mod)whistles %= mod;
            }
        }
        printf("%lld\n",whistles);
    }
return 0;
}
