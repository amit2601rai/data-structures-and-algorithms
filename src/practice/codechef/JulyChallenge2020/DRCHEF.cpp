/* Amit Rai(IIIT Hyderabad) */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--) {
		ll days = 0;
		ll n, x;
		cin>>n>>x;
		priority_queue<pair<ll,ll> > h;
		for (int i = 1; i <= n; i++) {
			ll val;
			cin>>val;
			h.push(make_pair(val, val));
		}
		while (!h.empty()) {
			pair<ll, ll> e = h.top();
			h.pop();
			if (x < e.first) {
				h.push(make_pair(max(2*(e.first - x), e.second), e.second));
			}
			x = x*2;
			days++;
		}
		cout<<days<<endl;
	}
	return 0;
}
