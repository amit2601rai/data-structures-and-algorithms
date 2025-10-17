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

inline void mark(bool *vis, vi v){
    tr(vi, v){
        int index = (*it);
        vis[index] = true;
    }
}

int main(){
    int T;
    s(T);
    while(T--){
        int n, k;
        s(n);
        s(k);
        int *a = new int[n];
        bool *vis = new bool[n];
        init_1D(vis, n-1, false);
        ll sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){s(a[i]);sum += (ll)a[i];}
        if(k > n || sum % k != 0) {cout << "no" << endl;continue;}
        sum /= k;
        for(int i = 0; i < (1<<n); i++){
            vi v;
            ll tmpSum = 0;
            bool isValid = true;
            for(int k = n-1, t = 0; k >= 0; k--, t++){
                if(i & (1<<k)){
                    if(vis[t]) {isValid = false;break;}
                    v.pb(t);
                    tmpSum += (ll)a[t];
                }
            }
            if (isValid && tmpSum == sum){mark(vis, v);ans++;}
            if(ans == k)break;
        }
        bool sumFlag = true;
        for(int i=0; i<n; i++) if(!vis[i] && a[i] != 0) sumFlag = false;
        if(ans == k && sumFlag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
return 0;
}
