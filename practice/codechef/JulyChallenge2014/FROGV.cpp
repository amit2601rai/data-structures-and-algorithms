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

bool myComp(ii x,ii y){
    if(x.second > y.second) return false;
    else return true;
}
int main(){
    int n,p,k,x;
    scanf("%d%d%d",&n,&k,&p);
    vii v;
    FOR(i,1,n){
        scanf("%d",&x);
        v.pb(mp(i,x));
    }
    sort(v.begin(),v.end(),myComp);
    int preCompute[n+1];
    preCompute[v[0].first] = v[0].first;
    FOR(i,1,n){
        if(v[i].second - v[i-1].second > k)preCompute[v[i].first] = v[i].first;
        else preCompute[v[i].first] = preCompute[v[i-1].first];
    }
    int r,s;
    while(p--){
        scanf("%d%d",&r,&s);
        if(preCompute[r] == preCompute[s])printf("Yes\n");
        else printf("No\n");
    }
return 0;
}
