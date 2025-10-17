/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<string, string> ss;
typedef vector<int> vi;
typedef vector<ll> vll;
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

#define pb push_back
#define mp make_pair
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;

ll mod = 998244353;
vll fact(300005, 1);

ll power(ll a,ll b,ll m){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x = (x*y)%m;
        }
        y = (y*y)%m;
        b = b >> 1;
    }
    return x%m;
}

ll modInverse(ll a,ll m){
    return power(a, m-2, m);
}

ll nCr(ll n, ll r) {
	if(r > n) return 0;
	return ((fact[n]* modInverse(fact[r], mod) % mod) * modInverse(fact[n-r], mod) % mod) % mod;
}

bool mycomp(ii x, ii y) {
	if(x.first < y.first) return true;
	else if(x.first > y.first) return false;
	else return (x.second > y.second);
}

int main(){
	int n, k;
	cin>>n>>k;

    vii input;
	for (int i = 1; i <=n; i++) {
		int s, e;
		cin>>s>>e;
		input.pb({s, 1});
		input.pb({e, 0});
	}

	sort(input.begin(), input.end(), mycomp);

	// Precompute Fact
	for (ll i = 2; i < 300005; i++) {
		fact[i] = (fact[i-1]*i)%mod;
	}

	ll ans = 0;
	ll onLamps = 0;
	for (auto c:input) {
		if(c.second == 1) {
			if(onLamps >= k-1) {
				ans += nCr(onLamps, k-1);
			   if(ans >= mod) ans %= mod;
		    }
		    onLamps++;
	    } else onLamps--;
	} 
	cout<<ans<<endl;

	return 0;
}