/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i = 0; i<n; i++) {
			cin>>v[i];
		}
         
		bool increasing = true;
		for (int i = 1; i < n; i++) {
			if(v[i-1] <= v[i]) {
				increasing = false;
				break;
			} 
		}
		if(increasing) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
	return 0;
}
