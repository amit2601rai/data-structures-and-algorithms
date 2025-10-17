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

LL MAXVAL = 1000000000000000000LL;
vector<LL>v[60];

void preCompute(){
    FOR(i,1,1000000){
        LD tmp = pow((LD)i,3);
        v[3].pb((LL)tmp);
    }
    FOR(i,4,59){
        LL j = 0;
        while(true){
            LL tmp = MAXVAL/(j+1);
            if(tmp >= v[i-1][j] && v[i].size() < v[i-1].size()){
                v[i].pb(v[i-1][j]*(j+1));
                if(v[i].size()>=v[i-1].size())
                    break;
            }
            else break;
            j++;
        }
    }
}


LL root(LL x,int r){
    if(r>59)return 1;
    if(r == 1)return x;
    if(r == 2)return (LL)sqrt((LD)x);
    vector<LL>:: iterator it = upper_bound(v[r].begin(),v[r].end(),x);
    return it-v[r].begin();
}

int main(){
    preCompute();
    int T;
    scanf("%d",&T);
    while(T--){
        int n,q;
        scanf("%d%d",&n,&q);
        LL a[n+1];
        LL sum[n+1];
        sum[0] = 0;
        FOR(i,1,n){
            scanf("%lld",&a[i]);
            sum[i] = sum[i-1]+ a[i];
            if(sum[i] < 0)sum[i] += mod;
            if(sum[i]>=mod)sum[i] %= mod;
        }
        while(q--){
            LL x,ans = 0;
            scanf("%lld",&x);
            int index = n+1;
            FOR(i,1,n){
                LL p = root(x,i);
                if(p == 1){
                    index = i;
                    break;
                }
                if(p >= mod)p %= mod;
                LL tmp = p*(a[i]+mod)%mod;
                if(tmp >= mod)tmp %= mod;
                ans = ans + tmp;
                if(ans >= mod)ans %= mod;
            }
            if(index <= n){
                ans = ans + (sum[n]-sum[index-1]+mod)%mod;
                if(ans >= mod)ans %= mod;
            }
            printf("%lld ",ans);
        }
        printf("\n");
    }
return 0;
}
