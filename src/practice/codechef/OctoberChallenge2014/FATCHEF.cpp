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

const int mod = 1000000009;

bool myComp(pair<char,int>x, pair<char,int>y){
    return (x.second < y.second);
}

int main(){
    int T;
    s(T);
    while(T--){
        int n, m;
        s(n);
        s(m);
        vector<pair<char,int> >v;
        char x;
        int idx;
        while(m--){
            scanf("\n%c %d", &x,&idx);
            v.pb(mp(x,idx));
        }
        sort(v.begin(),v.end(),myComp);
        ll ans = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i].first != v[i-1].first){
                ans = ans*(ll)(v[i].second - v[i-1].second);
                if(ans >= mod) ans %= mod;
            }
        }
        printf("%lld\n",ans);
    }
return 0;
}


