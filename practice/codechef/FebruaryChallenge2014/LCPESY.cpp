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

#define pb push_back
#define mp make_pair
#define For(a, b) for (int i = a; i <= b; i++)
#define Rep(a, b) for (int j = a; j <= b; j++)
#define TRvi(c) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c) for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define Fill_1d(a,n,value) For(0,n){a[i]=value;}
#define Fill_2d(a,m,n,value) For(0,m) Rep(0,n){a[i][j]=value;}


int main(){
    int T;
    cin>>T;
    while(T--){
        string A,B;
        cin>>A>>B;
        int a[256],b[256];
        Fill_1d(a,255,0);
        Fill_1d(b,255,0);
        int lenA = A.size();
        int lenB = B.size();
        for(int i=0;i<lenA;i++)
            a[A[i]]++;
        for(int i=0;i<lenB;i++)
            b[B[i]]++;
        int ans = 0;
        For(0,255){
            ans += min(a[i],b[i]);
        }
        cout<<ans<<endl;
    }
return 0;
}
