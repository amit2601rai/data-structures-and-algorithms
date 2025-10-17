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

/*This method will not maintain relative order of elements.*/
/* Time Complexity : O(n) , Space Complexity : O(1)*/
void pivotPartition(int a[], int n){
    int x = 0;
    int l = -1;
    FOR(i,0,n-1) if(a[i] < x) swap(a[++l],a[i]);
    FOR(i,0,n-1) cout<<a[i]<<" ";
    cout<<endl;
    int neg = 0, pos = l+1;
    while(pos < n && neg < n){
        swap(a[neg],a[pos]);
        pos++;
        neg += 2;
    }
    FOR(i,0,n-1) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    s(n);
    int a[n];
    FOR(i,0,n-1) s(a[i]);
    pivotPartition(a,n);
    adhocScan(a,n);
return 0;
}
