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
        string b;
        string w;
        cin>>b;
        cin>>w;
        int hash[256];
        int hash2[256];
        init_1D(hash,255,0);
        init_1D(hash2,255,0);
        int blen = b.size();
        int wlen = w.size();
        for(int i=0; i<blen; i++)hash[b[i]] = 1;
        for(int i=0; i<wlen; i++)hash2[w[i]] = 1;
        int ans = 0;
        for(int i=0; i<256; i++){
            if(hash2[i] == 1){
                if(hash[i] == 1)ans++;
            }
        }
        p(ans);
    }
return 0;
}


