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

int graph[305][305];
int degree[305];
int visited[305];

void bfs(){
    queue<int>Q;
    Q.push(1);
    dis[1] = 0;
    while(!Q.empty()){
        int x = Q.front();

    }
}


int main(){
    init_2D(graph,304,304,0);
    init_1D(degree,304,0);
    int n, k, x, y;
    s(n);
    s(k);
    FOR(i,1,n-1){
        int x, y;
        s(x);
        s(y);
        degree[x]++;
        degree[y]++;
        graph[x][y] = graph[y][x] = 1;
    }
return 0;
}
