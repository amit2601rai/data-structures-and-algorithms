//Author:Amit Rai (IIIT-Hyderabad)
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define pb push_back
#define mp make_pair
#define For(a, b) for (int i = a; i <= b; i++)
#define Rep(a, b) for (int j = a; j <= b; j++)
#define TRvi(c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define Fill_1d(a,n,value) For(0,n){a[i]=value;}
#define Fill_2d(a,m,n,value) For(0,m) Rep(0,n){a[i][j]=value;}

int hash[1000001];

int main(){
    Fill_1d(hash,1000000,INT_MAX);
    int n,k;
    cin>>n>>k;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        hash[x] = min(hash[x],min(i,n-i+1));
    }
    int ans = INT_MAX;
    int low = 1,high = k-1;
    while(low<high){
        if(hash[low] != INT_MAX && hash[high] != INT_MAX)ans = min(ans,max(hash[low],hash[high]));
        low++;
        high--;
    }
    if(ans == INT_MAX)cout<<"-1"<<endl;
    else cout<<ans<<endl;
return 0;
}
