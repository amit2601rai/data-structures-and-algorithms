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
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

int main(){
    int n,k,w;
    cin>>n>>k>>w;
    int dp[n+1];
    int dp_k[n+1];
    memset1d(dp,n,0);
    memset1d(dp_k,n,0);
    string str;
    cin>>str;
    FOR(i,0,n-1){
        if(str[i] == '0')dp[i+1] = dp[i];
        else if(str[i] == '1')dp[i+1] = dp[i]+1;
        if(i+1>=k)dp_k[i+1] = dp_k[i-k+1]+((str[i] == '1') ? 1 : 0);
    }
    int x,y;
    while(w--){
        cin>>x>>y;
        int totalK = (y-x+1)/k;
        int oneK = dp_k[y]- dp_k[x-1];
        int zeroK =  totalK - oneK;
        int oneT = dp[y] - dp[x-1];
        cout<<oneT-oneK+zeroK<<endl;
        }
return 0;
}
