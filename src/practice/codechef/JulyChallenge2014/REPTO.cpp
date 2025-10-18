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

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL x,y,tmp,ans;
        scanf("%lld%lld",&x,&y);
        x = abs(x);
        y = abs(y);
        tmp = max(x,y) - min(x,y);
        if(tmp % 2 == 0)tmp = 2*tmp;
        else if(x>y)tmp = 2*tmp + 1;
        else tmp = 2*tmp - 1;
        ans = 2*min(x,y) + tmp;
        printf("%lld\n",ans);
    }
return 0;
}
