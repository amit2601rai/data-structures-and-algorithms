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

int searchZero(int b[], int n){
    FOR(i,1,n)if(b[i] != 0)return i;
    return 0;
}

int minVal(int b[], int idx, int n){
    int minVal = INT_MAX;
    FOR(i,idx,n){
        if(b[i] == 0) break;
        minVal = min(minVal, b[i]);
    }
    return minVal;
}

int main(){
    int n;
    ll k;
    scanf("%d %lld",&n, &k);
    int a[n+1];
    int maxVal = -1;
    FOR(i,1,n){
        s(a[i]);
        maxVal = max(maxVal, a[i]);
    }
    int b[n+1];
    FOR(i,1,n) b[i] = maxVal - a[i];
    ll ans = 0;
    while(true){
        int idx = searchZero(b, n);
        if(idx == 0) break;
        int mVal = minVal(b, idx, n);
        ans += mVal;
        FOR(i,idx,n){
            if(b[i] == 0) break;
            b[i] -= mVal;
        }
    }
    if(ans > k) ans = 0;
    else ans = 1LL + (k-ans);
    printf("%lld\n", ans);
return 0;
}


