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

//map<ii, int>M;

int gcd(int x,int y){
    int r;
    while(y != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

void buildTree(int root, int low, int high, int *segtree, int *input){
    if(low == high){
        segtree[root] = input[low];
        return;
    }
    int mid = (low+high)/2;
    buildTree(2*root, low, mid, segtree, input);
    buildTree(2*root + 1, mid + 1, high, segtree, input);
    segtree[root] = gcd(segtree[2*root], segtree[2*root+1]);
}

int queryTree(int root, int a, int b, int low, int high, int *segtree){
    if(a > high || b < low)
        return 0;
    if(a <= low && high <= b){
        return segtree[root];
    }
    int mid = (low+high)/2;
    int lgcd = 0, rgcd = 0;
    if(a <= mid)
        lgcd = queryTree(2*root,a,b,low,mid,segtree);
    if(b > mid)
        rgcd = queryTree(2*root+1,a,b,mid+1,high,segtree);
    return gcd(lgcd, rgcd);
}

int main(){
    int T;
    s(T);
    while(T--){
        int N, Q, L, R;
        s(N);
        s(Q);
        int *segtree = new int [4*N + 1];
        int *input = new int [N + 1];
        FOR(i, 1, N)s(input[i]);
        buildTree(1, 1, N, segtree, input);
        while(Q--){
            s(L);
            s(R);
            p(gcd(queryTree(1, 1 , L-1, 1, N, segtree), queryTree(1, R+1 , N, 1, N, segtree)));
        }
    }
return 0;
}
