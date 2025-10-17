/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int log2(int v)
{ /* Evaluates [log2 v] */
  static const unsigned MUL_DE_BRUIJN_BIT[] = 
  {
     0,  9,  1, 10, 13, 21,  2, 29, 11, 14, 16, 18, 22, 25,  3, 30,
     8, 12, 20, 28, 15, 17, 24,  7, 19, 27, 23,  6, 26,  5,  4, 31
  };

  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;

  return MUL_DE_BRUIJN_BIT[(v * 0x07C4ACDDu) >> 27];
}

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<ll>v(128, 0);
		while(n--) {
			int x;
			cin>>x;
			v[log2(x)]++;
		}

		ll ans = 0;
		ll two = 2;
		for (int i = 0; i < 128; i++) {
			ans = ans + (v[i]*(v[i]-1))/two;
		}
		cout<<ans<<endl;
	}
	return 0;
}
