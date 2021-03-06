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


/*Not Very Clean Code. Needs Improvement.*/
int partition(int a[], int low, int high){
    int k = low - 1;
    for(int i = low; i < high; i++) if(a[i] < a[high]) swap(a[++k],a[i]);
    swap(a[++k],a[high]);
return k;
}

/* K-th Smallest Element */
int kthSmallestElement(int a[], int low, int high, int k){
    if(low < high){
        int idx = partition(a, low, high);
        if(idx == k-1 ) {cout<<a[idx]<<endl; return;}
        kthSmallestElement(a, low, idx - 1, k);
        kthSmallestElement(a, idx+1, high, k);
    }
}

/** Main Starts From Here **/
int main(){
    int n, k;
    cin>>n>>k;
    int a[n];
    FOR(i,0,n-1) cin>>a[i];
    cout<<kthSmallestElement(a, 0, n-1, k)<<endl;
return 0;
}
