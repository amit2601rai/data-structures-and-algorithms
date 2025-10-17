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
		n = 4*n - 1;
		int mx = 0, my = 0;
		while(n--) {
			int x, y;
			cin>>x>>y;
			mx ^= x;
			my ^= y;
		}
		cout<<mx<<" "<<my<<endl;
	}
	return 0;
}
