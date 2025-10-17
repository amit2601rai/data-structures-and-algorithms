/*Amit Rai(IIIT Hyderabad)*/
 #include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<int, int> mi;
typedef set<int> si;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;
typedef priority_queue<ii, vii, greater<ii> > pminHeap;
typedef priority_queue<ii> pmaxHeap;

#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define REP(i,a,b) for(int i = a; i < b; i++)
#define init_1D(a,n,value) FOR(i,0,n)a[i]=value;
#define init_2D(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define s(x) scanf("%d",&x)
#define p(x) printf("%d\n",x)
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
#define all(c) (c).begin(),(c).end()
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main(){
    int n, c;
    s(n);
    s(c);
    int coins[n+1];
    FOR(i,1,n)s(coins[i]);
    int dp[n+1][c+1];
    init_2D(dp, n, c, INT_MAX);
    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=c; j++){
            if(j - coins[i] >= 0 && dp[i-1][j-coins[i]] != INT_MAX) dp[i][j] = min(dp[i-1][j-coins[i]] + 1, dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][c]<<endl;
return 0;
}
