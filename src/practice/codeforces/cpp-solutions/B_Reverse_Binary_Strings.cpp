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
		vi v(n);
		for (int i = 0; i < n; i++) {
			char x;
			cin>>x;
			v[i] = x - 48;
		}

		int ones = 0;
		int window = 0;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (v[i] == 1) {
				flag = true;
				window++;
			} else {
				if(window > 0) ones += (window - 1);
				flag = false;
				window = 0;
			}
		}
		if(window > 0) ones += (window - 1);

        int zeroes = 0;
		window = 0;
		flag = false;
		for (int i = 0; i < n; i++) {
			if (v[i] == 0) {
				flag = true;
				window++;
			} else {
				if(window > 0) zeroes += (window - 1);
				flag = false;
				window = 0;
			}
		}
		if(window > 0) zeroes += (window - 1);
		cout<<max(zeroes, ones)<<endl;
	}
	return 0;
}