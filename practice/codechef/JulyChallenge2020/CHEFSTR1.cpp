/*Amit Rai(IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		ll cur, prev = 0;
		ll ans = 0;
		cin>>prev;
		n--;
		while(n--) {
			cin>>cur;
			ans = ans + max(cur, prev) - min(cur, prev) - 1;
			prev = cur;
		}
		cout<<ans<<endl;
	}
	return 0;
}
