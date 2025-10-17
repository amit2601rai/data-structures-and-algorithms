//Author:Amit Rai (IIIT-Hyderabad)
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define FOR(a, b) for (int i = a; i <= b; i++)
#define REP(a, b) for (int j = a; j <= b; j++)
#define TRvi(c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define memset1d(a,n,value) FOR(0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(0,m) REP(0,n) a[i][j]=value;

bool myComp(ii p,ii q){
    return p.second>q.second;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        cin>>n>>m>>k;
        int color[n+1];
        int points[n+1][m+1];
        int cost[n+1][m+1];
        int diff[n+1];
        int curvalue[n+1];
        memset1d(diff,n,-1);
        FOR(1,n) scanf("%d",&color[i]);
        FOR(1,n) REP(1,m) scanf("%d",&points[i][j]);
        FOR(1,n) REP(1,m) scanf("%d",&cost[i][j]);
        FOR(1,n) REP(1,m) {
            diff[i] = max(diff[i],points[i][j] - cost[i][j]);
        }
        vii v;
        FOR(1,n){
            curvalue[i] = points[i][color[i]];
            v.pb(mp(i,diff[i]-curvalue[i]));
        }
        sort(v.begin(),v.end(),myComp);
        int len = v.size();
        int ans = 0;
        FOR(0,len-1){
            if(i<k)ans += diff[v[i].first];
            else ans += curvalue[v[i].first];
        }
        cout<<ans<<endl;
    }
return 0;
}

