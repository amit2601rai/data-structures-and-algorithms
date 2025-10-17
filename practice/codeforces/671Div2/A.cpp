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
		int oo = 0, ee = 0;
	    rep(i, 1, n) {
	    	char c;
	    	cin>>c;
	    	if(i%2 == 0 && (c - '0') % 2 == 0) ee++;
	        if(i%2 != 0 && (c - '0') % 2 != 0) oo++;
	    }
	    if(n%2 == 0) {
	    	if(ee > 0) cout<<2<<endl;
	    	else cout<<1<<endl;
	    } else {
	    	if(oo > 0) cout<<1<<endl;
	    	else cout<<2<<endl;
	    }
	}
	return 0;
}
