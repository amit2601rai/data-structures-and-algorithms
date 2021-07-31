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
typedef priority_queue<ii,vector<ii>, greater<ii> > minHeap;
typedef priority_queue<ii> maxHeap;

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


void subsetGeneration(vi v){
    int n = v.size();
    REP(mask,0,1<<n){
        REP(k,0,n){
            if((mask & (1<<k)) != 0)p(v[k]);//will print elements of subset
        }
      cout<<endl<<endl;
    }
}

/*Testing Code*/
int main(){
    int n,x;
    cin>>n;
    vi v;
    FOR(i,1,n)cin>>x,v.pb(x);
    subsetGeneration(v);
return 0;
}

