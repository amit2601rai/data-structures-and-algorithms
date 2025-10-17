/*Amit Rai(IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

#define pb push_back
#define mp make_pair
#define f(i,a, b) for (int i = a; i <= b; i++)
#define r(i,a,b) for(int i = b; i >= a; i--)
#define init1d(a,n,value) f(i,0,n)a[i]=value;
#define init2d(a,m,n,value) f(i,0,m) f(j,0,n) a[i][j]=value;
#define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main() {
	int T;
	cin>>T;
	while(T--) {
		int n, q;
		cin>>n>>q;
		string str;
		cin>>str;
		int c[26];
		init1d(c, 25, 0);
		for (int i = 0; i < str.length(); i++) {
			c[str[i]-97]++;
		}
		while(q--) {
			int C;
			cin>>C;
			ll ans = 0;
			for (int i = 0; i < 26; i++) {
				ans += max(0, c[i]-C);
			}
			cout<<ans<<endl;
		}
	}
return 0;
}