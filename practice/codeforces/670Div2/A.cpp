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
		vi v(101, 0);
		while(n--) {
			int x;
			cin>>x;
			v[x]++;
		}
		int mexa = -1, mexb = -1;
		rep(i, 0, 100) {
			if(v[i] == 0) {
				if(mexb == -1) {
					mexa = mexb = i;
					break;	
				} else {
					mexa = i;
					break;
				}
			} else if(v[i] == 1) {
				if(mexb == -1) mexb = i;
			}
		}
		if(mexa == -1) mexa = 101;
	    if(mexb == -1) mexb = 101;

		//cout<<mexa<<" "<<mexb<<endl;
		cout<<(mexa+mexb)<<endl;
	}
	return 0;
}
