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


bool isSubSeqKPossible(vi v, int n, int k, int val) {
	// odd indices
	int oddlen = 0;
	for (int i = 1; i <= n; i++) {
		if(v[i] <= val) {
			oddlen++;
			if(i + 1 <= n) {
				oddlen++;
				i++;
			}
		}
	}
    
    // even indices
    int evenlen = 1;
	for (int i = 2; i <= n; i++) {
		if(v[i] <= val) {
			evenlen++;
			if(i + 1 <= n) {
				evenlen++;
				i++;
			}
		}
	}

	return (oddlen >= k || evenlen >= k) ? true : false;

}

int main(){
	int n, k;
	cin>>n>>k;
	vi v(n+1);
	for(int i = 1; i <=n; i++) {
		cin>>v[i];
	}
	int low = 1, high = 1e9;
	while(high - low > 1) {
		int mid = (low + high)/2;
		if(isSubSeqKPossible(v, n, k, mid)) high = mid;
		else low = mid;
	}
	if(isSubSeqKPossible(v, n, k, low)) cout<<low<<endl;
	else cout<<high<<endl;
	return 0;
}
