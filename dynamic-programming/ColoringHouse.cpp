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
    int n;
    s(n);
    int cr, cb, cg;
    s(cr);
    s(cb);
    s(cg);
    int dp[3][n];
    init_2D(dp, 2, n-1, 0);
    dp[0][0] = cr;
    dp[1][0] = cb;
    dp[2][0] = cg;

    for(int i = 1; i<n; i++){
        dp[0][i] = min(dp[1][i-1], dp[2][i-1]) + cr;
        dp[1][i] = min(dp[0][i-1], dp[2][i-1]) + cb;
        dp[2][i] = min(dp[0][i-1], dp[1][i-1]) + cg;
    }
    cout<<min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1]))<<endl;
return 0;
}
