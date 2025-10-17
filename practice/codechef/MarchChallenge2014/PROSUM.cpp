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

typedef long long LL;
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
    int T;
    cin>>T;
    while(T--){
        LL ans = 0,temp;
        int n;
        cin>>n;
        int one[n+1];
        int zero[n+1];
        int two[n+1];
        int numbers[n+1];
        memset1d(zero,n,0);
        memset1d(one,n,0);
        memset1d(two,n,0);
        FOR(i,1,n){
            scanf("%d",&numbers[i]);
            zero[i] = zero[i-1]+((numbers[i] == 0) ? 1 : 0);
            one[i] = one[i-1]+((numbers[i] == 1) ? 1 : 0);
            two[i] = two[i-1]+((numbers[i] == 2) ? 1 : 0);
        }
        FOR(i,1,n){
            if(numbers[i] == 0)temp = 0;
            else if(numbers[i] == 1)temp = 0;
            else if(numbers[i] == 2)temp = (n-i) - (zero[n]-zero[i])-(one[n]- one[i])-(two[n]-two[i]);
            else temp = (n-i) - (zero[n]-zero[i])-(one[n]- one[i]);
            ans = ans+temp;
        }
        cout<<ans<<endl;
    }
return 0;
}
