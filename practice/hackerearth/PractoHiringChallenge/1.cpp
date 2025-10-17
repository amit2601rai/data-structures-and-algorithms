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

int balancedPartition(int a[],int n,int sum){
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
    for(int i=1; i<=sum; i++)
        dp[0][i] = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j-a[i]>=0)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int j=sum; j>=0; j--){
        if(dp[n][j])
            return j;
    }
}


void subsetGeneration(vi v){
    vi firstV;
    int n = v.size();
    int ans = INT_MAX;
    int thirdPartSum = 0;
    REP(mask,0,1<<n){
         thirdPartSum = 0;
         firstV.clear();
        REP(k,0,n){
            if((mask & (1<<k)) != 0)firstV.pb(v[k]);//will print elements of subset
            else thirdPartSum += v[k];
        }
    if(firstV.size() < 2) continue;
    int sum = 0;
    int nn = firstV.size();
    int a[nn+1];
    for(int i=0; i < firstV.size(); i++){
        sum += firstV[i];
        a[i+1] = firstV[i];
    }
    int tmp = sum;
    sum /= 2;
    int firstPartSum = balancedPartition(a,nn,sum);
    int secondPartSum = abs(tmp - firstPartSum);
    //cout<<firstPartSum<<" "<<secondPartSum<<" "<<thirdPartSum<<endl;
    ans = min(ans, max(firstPartSum,max(secondPartSum,thirdPartSum)));
    }
    cout<<ans<<endl;
}

int main(){
    int N;
    cin>>N;
    vi v;
    int x;
    FOR(i,1,N){
        cin>>x;
        //cout<<x<<endl;
        v.pb(x);
    }
    subsetGeneration(v);
return 0;
}


