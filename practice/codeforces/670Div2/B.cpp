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
#define memx(a, n, value) loop(i, 0, n, 1)a[i]=value;
#define memxy(a, m, n, value) loop(i, 0, m, 1) loop(j, 0, n, 1) a[i][j]=value;
#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define tr(c, val) for (const auto &val : c)
#define ispresent(c, val) if(c.find(val) != c.end())
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<ll> neg, pos;
		while(n--) {
			ll x;
			cin>>x;
			if (x < 0) neg.pb(abs(x));
			else pos.pb(x);
		}
		sort(neg.begin(), neg.end());
		sort(pos.begin(), pos.end());

		ll v1, v2, v3, v4, v5, v6;
		v1 = v2 = v3 = v4 = v5 = v6 = LLONG_MIN;

		int negSize = neg.size();
		int posSize = pos.size();

		if(negSize >= 5) {
			v1 = (-1)*(neg[0]*neg[1]*neg[2]*neg[3]*neg[4]);
		}

		if(posSize >= 1 && negSize >= 4) {
		    v2 = pos[posSize-1]*neg[negSize-1]*neg[negSize-2]*neg[negSize-3]*neg[negSize-4];
		}

		if(posSize >= 2 && negSize >= 3) {
		    v3 = (-1)*pos[0]*pos[1]*neg[0]*neg[1]*neg[2];
		}


		if(posSize >= 3 && negSize >= 2) {
			v4 = pos[posSize-1]*pos[posSize-2]*pos[posSize-3]*neg[negSize-1]*neg[negSize-2];

		}

		if(posSize >= 4 && negSize >= 1) {
			v5 = (-1)*pos[0]*pos[1]*pos[2]*pos[3]*neg[0];
		}

		if(posSize >= 5) {
			v6 = pos[posSize-1]*pos[posSize-2]*pos[posSize-3]*pos[posSize-4]*pos[posSize-5];
		}

		cout<<max(v1,max(v2,max(v3,max(v4,max(v5,v6)))))<<endl;
	}

	return 0;
}