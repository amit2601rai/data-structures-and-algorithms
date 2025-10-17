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

const int MAXN = 200020;
ll tree[MAXN];

void preProcess(int a[],int n){
    int b[n];
    REP(i,0,n)b[i] = a[i];
    sort(b, b+n);
    REP(i,0,n){
        int ind = int(lower_bound(b, b + n, a[i]) - b);
        a[i] = ind + 1;
    }
}

ll read(int idx){ll sum = 0;while(idx > 0){sum += tree[idx],idx -= (idx & -idx);}return sum;}

void update(int idx,int val,int n){while(idx <= n){tree[idx] += val,idx += (idx & -idx);}}

int main(){
    int T;
    s(T);
    while(T--){
        int n;
        s(n);
        int a[n];
        REP(i,0,n)s(a[i]);
        preProcess(a,n);
        init_1D(tree,MAXN,0);
        ll invnct = 0;
        for(int i = n-1; i >= 0; i--){invnct += read(a[i]-1),update(a[i],1,n);}
        printf("%lld\n",invnct);
    }
return 0;
}
