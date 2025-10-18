/*Amit Rai(IIIT Hyderabad)*/
 /**
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0.
If array is sorted in reverse order that inversion count is the maximum. Formally speaking, two elements a[i] and a[j] form an inversion
if a[i] > a[j] and i < j
**/
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


int mergeArray(int a[], int low, int mid, int high){
    int p = low, q = mid + 1;
    int c[high-low+1];
    int ans = 0, k = 0;
    while(p <= mid && q <= high){
        if(a[p] > a[q]) {ans += (mid - p + 1); c[k++] = a[q]; q++;}
        else {c[k++] = a[p]; p++;}
    }
    while(p <= mid){c[k++] = a[p]; p++;}
    while(q <= high){c[k++] = a[q]; q++;}
    k=0;
    FOR(i,low,high){a[i] = c[k++];}
return ans;
}


int inversionCount(int a[], int low , int high){
    if(low < high){
        int mid = (low + high)/2;
        return inversionCount(a, low, mid) + inversionCount(a, mid+1, high) + mergeArray(a, low, mid, high);
    }
return 0;
}

int main(){
    int T;
    s(T);
    while(T--){
        int n;
        s(n);
        int a[n+1];
        FOR(i,1,n) s(a[i]);
        cout<<inversionCount(a,1,n)<<endl;
    }
return 0;
}
