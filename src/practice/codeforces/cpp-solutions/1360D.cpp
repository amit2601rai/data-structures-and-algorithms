/*Amit Rai(IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin>>n>>k;
		int max_k = 1;
		for (int i = 1; i*i <= n; i++) {
			if(n % i == 0) {
				if (i <= k) {
					max_k = max(max_k, i);
				}
				if(n/i <= k) {
					max_k = max(max_k, n/i);
				}
			}
		}
		cout << n/max_k<<endl;
	}
	return 0;
}
