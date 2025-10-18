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
#define MAX 100000

/*   Range Sum
*    Queries:
*    0 x y   : Sum of all values in [x,y]
*    1 x y v : Add value v in [x,y]
*/

struct node{
    int data = 0;
    int lazyCounter = 0;
};
typedef struct node NODE;
NODE segTree[4*MAX+1];

void buildTree(int root, int low, int high, int input[]){
    if(low == high){
        segTree[root].data = input[low];
        return;
    }
    int mid = (low + high)/2;
    buildTree(2*root, low, mid, input);
    buildTree(2*root + 1, mid + 1, high, input);
    segTree[root].data = segTree[2*root].data + segTree[2*root + 1].data;
}

void updateTree(int root, int a, int b, int v, int low, int high){
    if(low > b || high < a) return;
    if(a <= low && high <= b){
        segTree[root].data += v*(high - low + 1);
        segTree[root].lazyCounter += v;
        return;
    }
    int mid = (low + high)/2;
    int lazyCounter = segTree[root].lazyCounter;
    int ltmpVal = lazyCounter*(mid - low + 1);
    int rtmpVal = lazyCounter*(high - mid);
    segTree[2*root].lazyCounter += lazyCounter;
    segTree[2*root + 1].lazyCounter += lazyCounter;
    segTree[2*root].data += ltmpVal;
    segTree[2*root + 1].data += rtmpVal;
    segTree[root].lazyCounter =  0;
    if(a <= mid) updateTree(2*root, a, b, v, low, mid);
    if(mid < b) updateTree(2*root + 1, a, b, v, mid + 1, high);
    segTree[root].data = segTree[2*root].data + segTree[2*root + 1].data;
}

int queryTree(int root, int a, int b, int low, int high){
    int lsum, rsum;
    lsum = rsum = 0;
    if(low > b || high < a) return 0;
    if(a <= low && high <= b) return segTree[root].data;
    int mid = (low + high)/2;
    int v = segTree[root].lazyCounter;
    int ltmpVal = v*(mid - low + 1);
    int rtmpVal = v*(high - mid);
    segTree[2*root].lazyCounter += v;
    segTree[2*root].data += ltmpVal;
    segTree[2*root + 1].lazyCounter += v;
    segTree[2*root + 1].data += rtmpVal;
    segTree[root].lazyCounter =  0;
    if(a <= mid) lsum = queryTree(2*root, a, b, low, mid);
    if(mid < b) rsum = queryTree(2*root + 1, a, b, mid + 1, high);
    return lsum + rsum;
}

int main(){
    int n;
    s(n);
    int input[n+1];
    FOR(i,1,n) s(input[i]);
    buildTree(1, 1, n, input);
    FOR(i,1,10) p(segTree[i]);
    int Q;
    s(Q);
    while(Q--){
        int type;
        s(type);
        if(type){
            int x, y, v;
            s(x);s(y);s(v);
            updateTree(1, x, y, v, 1, n);
        }else{
            int x, y;
            s(x);s(y);
            cout<<queryTree(1, x, y, 1, n)<<endl;
        }
    }
return 0;
}
