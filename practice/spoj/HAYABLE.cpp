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
#define MAX 1000005

int tree[MAX+1];

int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
return sum;
}

void update(int idx,int val,int n){
    while(idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main(){
    int n, k, l, r;
    s(n);
    s(k);
    while(k--){
        s(l);
        s(r);
        update(l,1,n);
        update(r+1,-1,n);
    }
    vi v;
    FOR(i,1,n){
        v.pb(read(i));
    }
    sort(v.begin(), v.end());
    n= (n+1)/2;
    p(v[n-1]);
return 0;
}


