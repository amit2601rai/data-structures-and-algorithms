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
    while(true){
        int n, x;
        vi v;
        s(n);
        if(n == 0) break;
        FOR(i,1,n){
            s(x);
            v.pb(x);
        }
        sort(v.begin(),v.end());
        LL ans = 0;
        for(int i = 0; i < n-2; i++){
            int k = i+2;
            for(int j = i+1; j<n; j++){
                int key = v[i] + v[j];
                while(k < n && key >= v[k]) ++k;
                ans += (LL)(k - j -1);
            }
        }
        LL nn = n;
        long long tot = (nn*(nn-1)*(nn-2))/(LL)6;
        printf("%lld\n", tot-ans);
    }
return 0;
}
