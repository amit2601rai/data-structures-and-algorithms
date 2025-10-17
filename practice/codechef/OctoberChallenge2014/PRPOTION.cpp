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

int checkMax(int max_p[]){
    if(max_p[1] >= max_p[2] && max_p[1] >= max_p[3])return 1;
    if(max_p[2] >= max_p[1] && max_p[2] >= max_p[3])return 2;
    return 3;
}

int main(){
    int T;
    s(T);
    while(T--){
        int n[4], m;
        int potion[4][101];
        int max_p[4];
        FOR(i,1,3) s(n[i]);
        s(m);
        FOR(k,1,3) FOR(i,1,n[k]) s(potion[k][i]);
        max_p[1] = max_p[2] = max_p[3] = -1;
        FOR(k,1,3) FOR(i,1,n[k]) max_p[k] = max(max_p[k],potion[k][i]);
        int ans = INT_MAX;
        while(m--){
            ans = min(ans,max(max_p[1],max(max_p[2],max_p[3])));
            int flag = checkMax(max_p);
            FOR(i,1,3){
                if(i == flag)FOR(k,1,n[i]) potion[i][k] /= 2;
            }
            max_p[1] = max_p[2] = max_p[3] = -1;
            FOR(k,1,3) FOR(i,1,n[k]) max_p[k] = max(max_p[k],potion[k][i]);
        }
        ans = min(ans,max(max_p[1],max(max_p[2],max_p[3])));
        p(ans);
    }
return 0;
}


