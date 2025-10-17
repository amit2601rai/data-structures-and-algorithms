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
		int l, r;
		cin>>l>>r;
		if (l > r/2 )cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
