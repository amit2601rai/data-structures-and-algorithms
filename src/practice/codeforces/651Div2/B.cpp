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
		int n;
		cin>>n;
		vi odd, even;
		for (int i = 1; i <=2*n; i++) {
			int val;
			cin>>val;
			if(val&1) odd.pb(i);
			else even.pb(i);
		}

		int so = 0, se = 0;


        if(even.size() == 0) {
        	so = 2;
        } else if(odd.size() == 0) {
        	se = 2;
        }
		else if ((even.size() & 1 ) && (odd.size() & 1)) {
			so = se = 1;
		} else {
			se = 2;
		}

		for(int i = so; i < odd.size(); i+=2) {
			cout<<odd[i]<<" "<<odd[i+1]<<endl;
		}

		for(int i = se; i < even.size(); i+=2) {
			cout<<even[i]<<" "<<even[i+1]<<endl;
		}
	}
	return 0;
}
