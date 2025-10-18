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

int find_kth(int a[], int b[], int size_a, int size_b, int k){
    if(size_a > size_b) return find_kth(b, a, size_b, size_a, k);
    if(size_a == 0 && size_b >0) return b[k-1];
    if(k ==1) return min(a[0], b[0]);
    int i =  min(size_a, k/2) ;
    int j =  min(size_b, k/2) ;
    if(a[i-1] > b[j-1]) return find_kth(a, b+j, size_a, size_b -j, k-j);
    else return find_kth(a+i, b, size_a-i, size_b,  k-i);
    return -1;
}

int main(){
    int size_a, size_b;
    cin>>size_a>>size_b;
    int a[size_a];
    int b[size_b];
    FOR(i,0,size_a-1) cin>>a[i];
    FOR(i,0,size_b-1) cin>>b[i];
    int k;
    cin>>k;
    printf("%d\n", find_kth(a,b,size_a, size_b, k));
return 0;
}
