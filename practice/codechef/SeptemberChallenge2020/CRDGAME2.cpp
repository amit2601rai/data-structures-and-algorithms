/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<string, string> ss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<ss> vss;
typedef map<string, string> mss;
typedef map<string, int> msi;
typedef map<int, int> mi;
typedef unordered_map<string, string> umss;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umi;
typedef set<int> sti;
typedef set<string> sts;
typedef stack<int> stki;
typedef stack<string> stks;
typedef queue<int> qi;
typedef queue<string> qs;
typedef deque<int> dqi;
typedef deque<string> dqs;
typedef unordered_set<int> usi;
typedef unordered_set<string> uss;
typedef priority_queue<int, vi, greater<int> > iMinHeap;
typedef priority_queue<int> iMaxHeap;
typedef priority_queue<ii, vii, greater<ii> > iiMinHeap;
typedef priority_queue<ii> iiMaxHeap;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rrep(i, b, a) for(int i = b; i >= a; i--)
#define memx(a, n, value) rep(i, 0, n)a[i]=value;
#define memxy(a, m, n, value) rep(i, 0, m) rep(j, 0, n) a[i][j]=value;
#define tr(c, val) for (const auto &val : c)
#define ispresent(c, val) if(c.find(val) != c.end())
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;

ll cal(int n) {
	ll ans = 1;
	ll two = 2;
	while (n--) {
		ans = (ans * two) % mod;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vi v;
		rep(i, 1, n) {
			int val;
			cin>>val;
			v.pb(val);
		}
		sort(v.begin(), v.end());
		ll ans = 1;
		ll two = 2;
		if (v[n-1] == v[n-2]) ans = (two * cal(n-2)) % mod;
		else ans = cal(n);
		cout<<ans<<endl;
	}
	return 0;
}
