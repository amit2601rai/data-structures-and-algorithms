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
#define MAX 10005


int tree1[MAX+1];
int tree2[MAX+1];

int query1(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree1[idx];
        idx -= (idx & -idx);
    }
return sum;
}

int query2(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
return sum;
}


int query(int b){
    return query1(b)*b - query2(b);
}

int query(int a,int b){
    return query(b) - query(a-1);
}

void update1(int idx,int val,int n){
    while(idx <= n){
        tree1[idx] += val;
        idx += (idx & -idx);
    }
}

void update2(int idx,int val,int n){
    while(idx <= n){
        tree2[idx] += val;
        idx += (idx & -idx);
    }
}

void update(int y,int z,int v,int n){
    update1(y,v,n);
    update1(z+1,-v,n);
    update2(y,v*(y-1),n);
    update2(z+1,-v*z,n);
}

int main(){
    int T;
    s(T);
    while(T--){
        init_1D(tree1, MAX, 0);
        init_1D(tree2, MAX, 0);
        int n, u, l, r, v, q, x;
        s(n);
        s(u);
        while(u--){
            s(l);
            s(r);
            s(v);
            l++,r++;
            update(l, r, v, n);
        }
        s(q);
        while(q--){
            s(x);
            x++;
            p(query(x, x));
        }
    }
return 0;
}


