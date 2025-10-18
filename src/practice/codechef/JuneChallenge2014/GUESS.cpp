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
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

ll gcd(ll x,ll y){
    ll r;
    while(y != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n,m,ea,oa,eb,ob,nu,de,g;
        scanf("%lld%lld",&n,&m);
        ea = oa = n/2;
        eb = ob = m/2;
        if(n%2 != 0)oa++;
        if(m%2 != 0)ob++;
        nu = ea*ob + oa*eb;
        de = n*m;
        g = gcd(nu,de);
        printf("%lld/%lld\n",nu/g,de/g);
    }

return 0;
}
