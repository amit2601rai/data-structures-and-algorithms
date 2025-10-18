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

LL sumV(LL s, LL e){
      if(s > e) return 0;
      return ((e-s+1)*(e+s))/2;
}

int main(){
    int T;
    s(T);
    while(T--){
        LL N, K;
        cin>>N>>K;
        LL num[K];
        LL sum;
        sum = (N*(N+1))/2;
        FOR(i,0,K-1) cin>>num[i];
        sort(num, num+K);
        if(K != 0){
            sum = ((num[0]-1)*num[0])/2;
            LL s = 1;
            LL e = sum;
            bool flag = true;
            FOR(i,0,K-1){
                LL tmp = e;
                if(i != 0) tmp = tmp + sumV(num[i-1]+1, num[i]-1);
                if(tmp >= num[i]) e = tmp;
                else {flag = false; break;}
            }
            if(flag) e = e + sumV(num[K-1]+1, N);
            sum = e;
        }
        if(sum % 2 != 0) cout<<"Mom"<<endl;
        else cout<<"Chef"<<endl;
    }
return 0;
}
