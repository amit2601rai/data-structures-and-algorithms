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

int main(){
	int t;
	cin>>t;
	while(t--) {
		int m, n;
		cin>>n>>m;
		ll a[n][m];
		for (int i = 0; i<n; i++) {
			for(int j = 0; j<m; j++) {
				cin>>a[i][j];
			}
		}

		int row_low = 0, row_high = n-1;
		ll ans = 0;
		while(row_low <= row_high) {
			int col_low = 0, col_high = m-1;
			if(row_low == row_high) {
				while(col_low <= col_high) {
					ll p = a[row_low][col_low];
					ll q = a[row_low][col_high];
					ans += max(p,q) - min(p,q);
					col_low++;
					col_high--;
				}

			} else {
				while(col_low <= col_high) {
					if(col_low == col_high) {
						ll p = a[row_low][col_low];
				        ll q = a[row_high][col_low];
				        ans += max(p,q) - min(p,q);
					} else {
						ll p = a[row_low][col_low];
				        ll q = a[row_low][col_high];
			            ll r = a[row_high][col_low];
			            ll s = a[row_high][col_high];
			            vector<long long> v;
			            v.pb(p);
			            v.pb(q);
			            v.pb(r);
			            v.pb(s);
			            sort(v.begin(), v.end());
			           ans += abs(p-v[1]) + abs(q-v[1]) + abs(r-v[1]) + abs(s-v[1]);
					}
			        col_low++;
			        col_high--;
			    }
			}
		    row_low++;
		    row_high--;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
