/*Amit Rai(IIIT Hyderabad)*/
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>

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
typedef priority_queue<int, vi, greater<int> > iMinHeap;
typedef priority_queue<int> iMaxHeap;
typedef priority_queue<ii, vii, greater<ii> > iiMinHeap;
typedef priority_queue<ii> iiMaxHeap;

#define pb push_back
#define mp make_pair
#define f(i,a, b) for (int i = a; i <= b; i++)
#define r(i,a,b) for(int i = a; i < b; i++)
#define init1d(a,n,value) f(i,0,n)a[i]=value;
#define init2d(a,m,n,value) f(i,0,m) f(j,0,n) a[i][j]=value;
#define s(x) scanf("%d",&x)
#define p(x) printf("%d\n",x)
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
#define all(c) (c).begin(),(c).end()
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main(){
	int T;
	cin>>T;
	while(T--) {
		int N;
		cin>>N;
		ll zeros = 0, twos = 0;
		while(N--) {
			ll x;
			cin>>x;
			if(x == 0) zeros++;
			if(x == 2) twos++;
		}
		ll ans = (zeros*(zeros - 1))/2 + (twos*(twos - 1))/2;
		cout<<ans<<endl;
	}
return 0;
}