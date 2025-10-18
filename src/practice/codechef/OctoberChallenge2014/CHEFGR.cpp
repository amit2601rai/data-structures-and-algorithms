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

int main(){
    int T;
    s(T);
    while(T--){
        int n, m;
        s(n);
        s(m);
        int sum = 0;
        int a[n+1];
        FOR(i,1,n){
            s(a[i]);
            sum += a[i];
        }
        bool check = false;
        if((sum + m)%n == 0){
            check = true;
            sum = (sum + m)/n;
            FOR(i,1,n){
                if(a[i] > sum){
                    check = false;
                    break;
                }
            }
        }
        if(check)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
return 0;
}


