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

ll a[100001];
ll b[100001];
int main(){
    int n;
    cin>>n;
    ll ans = 0;
    FOR(i,1,n)cin>>a[i];
    FOR(i,1,n)cin>>b[i];
    FOR(i,1,n){
        ll temp;
        if(b[i] == 1){ans--;continue;}
        temp = b[i]/2;
        if(b[i]%2 != 0)temp++;
        if(a[i]<temp)ans--;
        else{
            ans = ans+temp*(b[i]-temp);
        }
    }
    cout<<ans<<endl;
return 0;
}
