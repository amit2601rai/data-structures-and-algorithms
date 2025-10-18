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
#define tr(c,it) for(typeof(c).begin() it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int>inc(n);
	vector<int>dec(n);
	vector<int>elem(n);
	int prev, val;
	inc[0] = dec[0] = 0;
	bool f1, f2;
	f1 = f2 = false;
	scanf("%d", &prev);
	elem[0] = prev;
	f(i, 1, n-1) {
		scanf("%d", &val); 
		elem[i] = val;
		if(val > prev) {
			inc[i] = inc[i-1] + (f1 ? 0 : 1);
			dec[i] = dec[i-1];
			f1 = true;
			f2 = false;
		} else {
			dec[i] = dec[i-1] + (f2 ? 0 : 1);
			inc[i] = inc[i-1];
			f1 = false;
			f2 = true;
		}
		prev = val;
	}

	while (q--) {
		int l, r;
		scanf("%d%d",&l, &r);
		l--;
		r--;
	    int maxInc = 0, maxDec = 0;

	    if(l == 0) maxInc = inc[r];
	    else if(elem[l-1] < elem[l] && (l < n-1 && elem[l] < elem[l+1])) maxInc = inc[r] - inc[l-1] + (inc[l] == inc[l-1] ? 1 : 0);
	    else if(elem[l-1] < elem[l] && (l < n-1 && elem[l] > elem[l+1])) maxInc = inc[r] - inc[l];
	    else maxInc = inc[r] - inc[l-1];

        if(l == 0) maxDec = dec[r];
	    else if(elem[l-1] > elem[l] && (l < n-1 && elem[l] > elem[l+1])) maxDec = dec[r] - dec[l-1] + (dec[l] == dec[l-1] ? 1 : 0);
	    else if(elem[l-1] > elem[l] && (l < n-1 && elem[l] < elem[l+1])) maxDec = dec[r] - dec[l];
	    else maxDec = dec[r] - dec[l-1];

		if(maxInc == maxDec) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
