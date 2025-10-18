/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair

ll mod = 1e9+7;
ll two = 2;
ll one = 1;
ll ten = 10;

ll mul(ll a, ll b) {
	return (((a*b)%mod+mod)%mod);
}

ll add(ll a, ll b) {
	return (((a+b)%mod+mod)%mod);
}

ll comb2(ll  n) {
	return add(n*(n+1)/two,0);
}

int main(){
	string input;
	cin>>input;
	int len = input.size();
	vector<ll> v(len);
	int idx = len - 1;
	for(auto c:input) {
		v[idx--] = c - '0';
	}	

	ll ans = 0;
	ll back = 0;
	ll tenVal = 1;
	ll tenVal2 = 1;
	for(int i = 0; i < len; i++) {
		ans = add(ans,mul(mul(v[i], tenVal), comb2(len-i-1)));
		if(i > 0) {
			back = add(back, mul(i, tenVal2));
			ans = add(ans, mul(back, v[i]));
			tenVal2 = mul(tenVal2, ten);
		}
		tenVal = mul(tenVal, ten);
	}
	cout<<ans<<endl;
	return 0;
}
