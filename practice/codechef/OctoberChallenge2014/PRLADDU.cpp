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


int main(){
    int T;
    s(T);
    while(T--){
        int n;
        s(n);
        int a[n+1];
        int pos, neg;
        ll ans = 0;
        pos = neg = 0;
        FOR(i,1,n){
            s(a[i]);
            if(pos == 0 && a[i] > 0)pos = i;
            if(neg == 0 && a[i] < 0)neg = i;
        }
        while(max(pos,neg) <= n && pos != 0 && neg != 0){
            if (abs(a[pos]) == abs(a[neg])) ans += (ll)(abs(pos - neg)*a[pos]),a[pos] = a[neg] = 0, pos++, neg++;
            else if (abs(a[pos]) < abs(a[neg])) ans += (ll)(abs(pos - neg)*a[pos]), a[neg] += a[pos], a[pos] = 0, pos++;
            else ans += (ll)(abs(pos - neg)*abs(a[neg])), a[pos]+= a[neg], a[neg] = 0, neg++;
            while(pos <= n && a[pos] <= 0) pos++;
            while(neg <= n && a[neg] >= 0) neg++;
        }
        printf("%lld\n",ans);
    }
return 0;
}


