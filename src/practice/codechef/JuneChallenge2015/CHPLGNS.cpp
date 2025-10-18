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


bool comp(pair<int,int>x, pair<int,int>y) {
	return (x.first<=y.first);
}


int main() {
	int T;
	s(T);
	while(T--) {
		int n;
		s(n);
		vii v;
		for(int k = 0; k < n; k++) {
			int t;
			s(t);
			int maxVal = -1;
			for(int i = 1; i <= 2*t; i++) {
				int x;
				s(x);
				if(x < 0) x *= -1;
				maxVal = max(maxVal, x);
			}
			v.pb(mp(maxVal,k));
		}
		sort(v.begin(), v.end(), comp);
		int *ans = new int[n];
		for(int i = 0; i < v.size(); i++) {
			ans[v[i].second] = i;
		}
		for(int i = 0; i < n; i++) {
			printf("%d ",ans[i]);
		}
	    printf("\n");
	}
return 0;
}