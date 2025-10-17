/*Amit Rai(IIIT Hyderabad)*/
 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
#define tr(type,container) type :: iterator it; for(it = container.begin(); it!= container.end(); it++)
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;

//dp[i][j] : XOR j is possible after processing i elements
int maxXOR(int *input, int k, int n){
    bool dp[n+1][2048];
    init_2D(dp, n, 2047, false);
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2048; j++ ){
            dp[i][j] = dp[i-1][j] || dp[i-1][j^input[i]];
        }
    }
    int ans = 0;
    for(int j = 0; j < 2048; j++){
        if(dp[n][j]) ans = max(ans, k^j);
    }
return ans;
}

int main(){
    int T;
    s(T);
    while(T--){
        int n, k;
        s(n);
        s(k);
        int *input = new int[n+1];
        FOR(i,1,n){
            s(input[i]);
        }
        p(maxXOR(input, k, n));
    }
return 0;
}
