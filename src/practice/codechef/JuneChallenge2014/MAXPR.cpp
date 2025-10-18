//Amit Rai (IIIT-Hyderabad)
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
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)
#define mod 1000000007

ll power(ll a,int b){
    long long x=1,y=a;
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
    cin>>T;
    while(T--){
        int n,x;
        scanf("%d",&n);
        ll dps[101][201];
        ll vis[101];
        memset1d(vis,100,0);
        memset2d(dps,100,200,0);
        for(int i=1; i<=n; i++){
            scanf("%d",&x);
            vis[x]++;
            for(int j=0; j<=198; j++){
                int d = j - 99;
                if(x-d>=1 && x-d<=100 && vis[x-d] != 0){
                    if(d == 0)dps[x][j] = dps[x][j]+dps[x-d][j]+1;
                    else dps[x][j] = dps[x][j]+dps[x-d][j]+vis[x-d];
                }
                if(dps[x][j] >= mod)dps[x][j] %= mod;
            }
        }
        ll totalAPSubseq = 0;
        FOR(i,1,100){
            FOR(j,0,198){
                totalAPSubseq += dps[i][j];
                if(totalAPSubseq >= mod)totalAPSubseq %= mod;
            }
        }
        totalAPSubseq = (totalAPSubseq + 1)%mod;
        ll totalSubseq = power(2,n);
        ll ans = (totalSubseq - totalAPSubseq + mod)%mod;
        printf("%lld\n",ans);
    }
return 0;
}
