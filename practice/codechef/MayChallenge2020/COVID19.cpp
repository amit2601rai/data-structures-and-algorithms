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
		int n;
		cin>>n;
		int curInf = 1;
		int maxInf = -1, minInf = -1;
		int x, y;
		cin>>x;
		f(i, 2, n) { 
			cin>>y;
			if(y - x > 2) {
				if (maxInf == -1 )maxInf = curInf;
				else maxInf = max(curInf, maxInf);
				if(minInf == -1) minInf = curInf;
				else minInf = min(curInf, minInf);
				curInf = 1;
			} else {
				curInf++;
			}
			x = y;
		}
		if (maxInf == -1 )maxInf = curInf;
		else maxInf = max(curInf, maxInf);
		if(minInf == -1) minInf = curInf;
		else minInf = min(curInf, minInf);

		cout<<minInf<<" "<<maxInf<<endl;
	}
return 0;
}