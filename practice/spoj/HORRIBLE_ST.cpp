/*Author:Amit(IIIT-H)*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define INF INT_MAX
#define MINF INT_MIN
#define MAX  400000
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

struct node{
    ll sum;
    ll value;
};
typedef struct node Node;


void lazyUpdate(int root,int a,int b,int low,int high,int v,Node tree[]){
    if(a > high || b < low)
        return;
    if(a <= low && high <= b){
        tree[root].sum += ((ll)(high-low+1)*v);
        tree[root].value += v;
        return;
    }
    int mid = (low+high)/2;
    ll tmpVal = tree[root].value;
    if(tmpVal != 0){
        tree[2*root].sum += ((ll)(mid-low+1)*tmpVal);
        tree[2*root].value += tmpVal;
        tree[2*root+1].sum += ((ll)(high-mid)*tmpVal);
        tree[2*root+1].value += tmpVal;
        tree[root].value = 0;
    }
    if(a <= mid)
        lazyUpdate(2*root,a,b,low,mid,v,tree);
    if(b > mid)
        lazyUpdate(2*root+1,a,b,mid+1,high,v,tree);
    tree[root].sum = tree[2*root].sum + tree[2*root+1].sum;
}

ll query(int root,int a,int b,int low,int high,Node tree[]){
    if(a > high || b < low)
        return 0;
    if(a <= low && high <= b){
        return tree[root].sum;
    }
    int mid = (low+high)/2;
    ll tmpVal = tree[root].value;
    if(tmpVal != 0){
        tree[2*root].sum += ((ll)(mid-low+1)*tmpVal);
        tree[2*root].value += tmpVal;
        tree[2*root+1].sum += ((ll)(high-mid)*tmpVal);
        tree[2*root+1].value += tmpVal;
        tree[root].value = 0;
    }
    ll lsum = 0,rsum = 0;
    if(a <= mid)
        lsum = query(2*root,a,b,low,mid,tree);
    if(b > mid)
        rsum = query(2*root+1,a,b,mid+1,high,tree);
    return lsum+rsum;
}

void init_tree(Node tree[]){
    FOR(i,1,MAX){
        tree[i].sum = 0;
        tree[i].value = 0;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,q,f,a,b;
        ll v;
        scanf("%d%d",&n,&q);
        Node* tree = new Node[MAX+1];
        init_tree(tree);
        while(q--){
            scanf("%d%d%d",&f,&a,&b);
            if(f == 0){
                scanf("%lld",&v);
                lazyUpdate(1,a,b,1,n,v,tree);
            }else{
                printf("%lld\n",query(1,a,b,1,n,tree));
            }
        }
    }
return 0;
}
